#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int balance = 1000;
//pthread_mutex_t lock;

void* deposit(void* arg) {
    for (int i = 0; i < 5; ++i) {
        //pthread_mutex_lock(&lock);
        balance += 100;
        printf("Deposited 100, balance: %d\n", balance);
        //pthread_mutex_unlock(&lock);
        sleep(1);
    }
    return NULL;
}

void* withdraw(void* arg) {
    for (int i = 0; i < 5; ++i) {
        //pthread_mutex_lock(&lock);
        if (balance >= 50) {
            balance -= 50;
            printf("Withdrew 50, balance: %d\n", balance);
        } else {
            printf("Insufficient funds to withdraw\n");
        }
        //pthread_mutex_unlock(&lock);
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;
    //pthread_mutex_init(&lock, NULL);

    pthread_create(&t1, NULL, deposit, NULL);
    pthread_create(&t2, NULL, withdraw, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    //pthread_mutex_destroy(&lock);
    printf("Final balance: %d\n", balance);
    return 0;
}
