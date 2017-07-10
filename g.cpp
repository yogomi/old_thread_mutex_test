#include "./g.h"
#include <pthread.h>
#include <iostream>

namespace G {

void* G(void *args) {
  struct args_for_g* param = static_cast<struct args_for_g*>(args);
  if (args == NULL) {
    printf("args == NULL\n");
  }
  for (int i = 0; i < 70; i++) {
    pthread_mutex_lock(param->mutex);
    std::cout << "abcde";
    std::cout << "fghi";
    std::cout << "jklm";
    std::cout << "nopqrstu";
    std::cout << "vwxyz";
    std::cout << std::endl;
    pthread_mutex_unlock(param->mutex);
  }
  return NULL;
}

}
