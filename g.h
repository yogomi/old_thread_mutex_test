#include <pthread.h>

namespace G{

struct args_for_g {
  pthread_mutex_t* mutex;
};

void* G(void *args);

}
