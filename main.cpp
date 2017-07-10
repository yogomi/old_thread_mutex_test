// Copyright 2017 Makoto Yano"

#include <unistd.h>
#include <pthread.h>
#include <iostream>

#include "g.h"

struct args_for_f {
  pthread_mutex_t* mutex;
};

void* F(void *args) {
  struct args_for_f* param = static_cast<struct args_for_f*>(args);
  if (args == NULL) {
    printf("args == NULL\n");
  }
  for (int i = 0; i < 100; i++) {
    pthread_mutex_lock(param->mutex);
    std::cout << "012345";
    std::cout << "6789";
    std::cout << std::endl;
    pthread_mutex_unlock(param->mutex);
  }
  return NULL;
}

int main() {
  pthread_t thread_f;
  pthread_t thread_g;

  pthread_mutex_t mutex;
  pthread_mutex_init(&mutex, NULL);

  struct args_for_f f_param;
  f_param.mutex = &mutex;

  struct G::args_for_g g_param;
  g_param.mutex = &mutex;

  pthread_create(&thread_f, NULL, F, &f_param);
  pthread_create(&thread_g, NULL, G::G, &g_param);

  sleep(1);

  pthread_mutex_destroy(&mutex);

  return 0;
}
