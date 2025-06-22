/*
 * Project 18: Multithreading with POSIX Threads (pthreads)
 * Author: Bocaletto Luca
 * Date: 2025-06-22
 * GitHub: bocaletto-luca
 *
 * Description:
 * This program spawns multiple threads that concurrently increment a shared counter.
 * A mutex is used to protect the shared variable from race conditions. Each thread
 * performs a fixed number of increments, and the final counter value is printed after
 * all threads have completed their work.
 *
 * Key Concepts:
 * - Creating threads using pthread_create().
 * - Synchronizing threads with pthread_mutex for safe access to shared data.
 * - Joining threads with pthread_join() to ensure all threads complete before proceeding.
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5
#define INCREMENTS_PER_THREAD 100000

// Global shared counter that will be incremented by multiple threads.
long counter = 0;

// Mutex to protect access to the shared 'counter' variable.
pthread_mutex_t counter_mutex;

/*
 * Function: threadFunction
 * ------------------------
 * Each thread executes this function. It loops for a fixed number of increments,
 * and in each iteration, it locks the mutex, increments the counter, and then unlocks
 * the mutex to allow other threads to access the shared counter.
 *
 * arg: A pointer to any argument we want to pass (unused in this example).
 *
 * returns: NULL upon completion.
 */
void *threadFunction(void *arg) {
    for (int i = 0; i < INCREMENTS_PER_THREAD; i++) {
        // Lock the mutex before updating the shared counter.
        pthread_mutex_lock(&counter_mutex);
        counter++;  // Critical section: update shared variable.
        // Unlock the mutex to allow other threads access to the counter.
        pthread_mutex_unlock(&counter_mutex);
    }
    return NULL;
}

/*
 * Function: main
 * --------------
 * Sets up the multithreading environment by initializing the mutex, creating threads,
 * waiting for them to finish execution, and then cleaning up before exiting.
 */
int main(void) {
    pthread_t threads[NUM_THREADS];
    int i, status;
    
    // Initialize the mutex with default attributes.
    if (pthread_mutex_init(&counter_mutex, NULL) != 0) {
        printf("Error initializing mutex.\n");
        exit(EXIT_FAILURE);
    }
    
    // Create multiple threads.
    for (i = 0; i < NUM_THREADS; i++) {
        status = pthread_create(&threads[i], NULL, threadFunction, NULL);
        if (status != 0) {
            printf("Error creating thread %d.\n", i);
            exit(EXIT_FAILURE);
        }
    }
    
    // Wait for all threads to finish.
    for (i = 0; i < NUM_THREADS; i++) {
        status = pthread_join(threads[i], NULL);
        if (status != 0) {
            printf("Error joining thread %d.\n", i);
            exit(EXIT_FAILURE);
        }
    }
    
    // Destroy the mutex after use.
    pthread_mutex_destroy(&counter_mutex);
    
    // Calculate the expected counter value.
    long expected = NUM_THREADS * INCREMENTS_PER_THREAD;
    printf("Final counter value: %ld (expected: %ld)\n", counter, expected);
    
    return 0;
}
