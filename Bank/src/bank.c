#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include "bank.h"

void* deposit(void* arg){

    for(int i=0;i<5;i++){
        pthread_mutex_lock(&lock);
        balance+=100;
        pthread_mutex_unlock(&lock);
        printf("Deposit 100 euros, the balance is: %d\n", balance);
    }
    sleep(1);
    return NULL;
}
void* withdraw(void* arg){
    
    for(int i=0;i<5;i++){
        if(balance>=50){
            pthread_mutex_lock(&lock);
            balance-=50;
            pthread_mutex_unlock(&lock);
            printf("Withdraw 50 euros, the balance is %d\n",balance);
        }
       else
        {
        printf("You dont have enough money\n");
        } 
    }   
    sleep(1);
    return NULL;

}