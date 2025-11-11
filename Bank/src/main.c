#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include "bank.h"

int balance = 1000;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

int main() {
   
    pthread_t t1, t2;

    pthread_mutex_init(&lock,NULL);

    pthread_create(&t1,NULL,deposit,NULL);
    pthread_create(&t2,NULL,withdraw,NULL);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);

    pthread_mutex_destroy(&lock);

    return 0;
}