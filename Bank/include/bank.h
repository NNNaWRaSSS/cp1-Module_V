#ifndef BANK_H
#define BANK_H
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

extern int balance;
extern pthread_mutex_t lock;

void* deposit(void* arg);
void* withdraw(void* arg);

#endif