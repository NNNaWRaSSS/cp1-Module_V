#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int x = 2;

void* routine() {
    x += 5;
    sleep(2);
    printf("Value of x: %d\n", x);
    printf("The id of the process: %d\n", getpid());
}

void* routine2() {
    sleep(2);
    printf("Value of x: %d\n", x);
    printf("The id of the process: %d\n", getpid());
}

int main(int argc, char* argv[]) {
    printf("The id of the process: %d\n", getpid());
    pthread_t t1, t2;
    if (pthread_create(&t1, NULL, &routine, NULL)) {
        return 1;
    }
    if (pthread_create(&t2, NULL, &routine2, NULL)) {
        return 2;
    }
    if (pthread_join(t1, NULL)) {
        return 3;
    }
    if (pthread_join(t2, NULL)) {
        return 3;
    }
    return 0;
}