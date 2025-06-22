/*
 * Project 17: Memory Management and Pointer Exercises
 * Author: Bocaletto Luca
 * Date: 2025-06-22
 * GitHub: bocaletto-luca
 *
 * Description:
 * This project contains a series of exercises that focus on memory management
 * in C. It explores:
 * - Dynamically allocating memory using malloc() and calloc().
 * - Performing pointer arithmetic to traverse and manipulate memory.
 * - Releasing allocated memory using free() to avoid memory leaks.
 * - Debugging common issues such as segmentation faults when dealing with pointers.
 *
 * Key Concepts:
 * - Dynamic memory allocation and deallocation.
 * - Pointer arithmetic and array indexing.
 * - Proper error handling when dealing with memory operations.
 */

#include <stdio.h>
#include <stdlib.h>

// Function: allocateArray
// -----------------------
// Dynamically allocates an array of integers of given size, initializes the array,
// and returns a pointer to the allocated memory.
// Parameters:
//   size: Number of integers to allocate.
// Returns: Pointer to the allocated array, or NULL if allocation fails.
int* allocateArray(int size) {
    // Use malloc to allocate memory for 'size' integers.
    int *array = (int *) malloc(size * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);  // Exit if memory allocation fails.
    }
    
    // Initialize the allocated memory with indices (for demonstration).
    for (int i = 0; i < size; i++) {
        array[i] = i;
    }
    
    return array;
}

// Function: pointerTraversal
// --------------------------
// Demonstrates pointer arithmetic by traversing and printing all elements of an array.
// Parameters:
//   array: Pointer to the first element of the array.
//   size:  Number of elements in the array.
void pointerTraversal(int *array, int size) {
    printf("Traversing array elements using pointer arithmetic:\n");
    int *ptr = array; // Initialize pointer to the array's first element.
    for (int i = 0; i < size; i++) {
        printf("Element %d: %d\n", i, *(ptr + i));
    }
}

// Function: reallocateArray
// -------------------------
// Demonstrates changing the size of an allocated array using realloc().
// It doubles the size of the array while preserving the existing elements.
// Parameters:
//   array: Pointer to the previously allocated array.
//   currentSize: Current size of the array.
// Returns: Pointer to the reallocated (larger) array.
int* reallocateArray(int *array, int currentSize) {
    int newSize = currentSize * 2;
    int *newArray = (int *) realloc(array, newSize * sizeof(int));
    if (newArray == NULL) {
        printf("Reallocation failed.\n");
        free(array);  // Free the original memory if reallocation fails.
        exit(1);
    }
    
    // Initialize the newly allocated portion.
    for (int i = currentSize; i < newSize; i++) {
        newArray[i] = i;
    }
    
    return newArray;
}

int main(void) {
    int size = 5;   // Initial size of the array.
    
    // Allocate memory for the array.
    int *array = allocateArray(size);
    
    // Traverse and print the allocated array using pointer arithmetic.
    pointerTraversal(array, size);
    
    // Reallocate the array to double its size.
    array = reallocateArray(array, size);
    printf("\nAfter reallocation:\n");
    
    // Update size to reflect the new allocation.
    size *= 2;
    pointerTraversal(array, size);
    
    // Free the allocated memory to prevent memory leaks.
    free(array);
    
    // Indicate successful execution.
    printf("Memory operations completed successfully.\n");
    
    return 0;
}
