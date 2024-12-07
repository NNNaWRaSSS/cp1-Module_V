#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4
#define ARRAY_SIZE 10

int shared_array[ARRAY_SIZE] = {0};  // Shared resource
pthread_mutex_t mutex;               // Mutex to protect the shared array

void* update_array(void* arg) {
    int index = *(int*)arg;
    free(arg);

    // Update shared array in a safe way
    pthread_mutex_lock(&mutex);  // Lock the mutex
    shared_array[index] += 1;    // Update the array
    pthread_mutex_unlock(&mutex);  // Unlock the mutex

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];

    // Initialize the mutex
    pthread_mutex_init(&mutex, NULL);

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        int* index = malloc(sizeof(int));
        *index = i % ARRAY_SIZE;  // Ensure index is within array bounds
        if (pthread_create(&threads[i], NULL, update_array, index) != 0) {
            perror("Thread creation failed");
            exit(EXIT_FAILURE);
        }
    }

    // Wait for threads to complete
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy the mutex
    pthread_mutex_destroy(&mutex);

    // Print the final state of the shared array
    printf("Final shared array values:\n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", shared_array[i]);
    }
    printf("\n");

    return 0;
}