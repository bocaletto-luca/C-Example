/*
 * Project 9: Sorting Algorithms: Bubble Sort and Insertion Sort
 * Author: Bocaletto Luca
 * Date: 2025-06-22
 * GitHub: bocaletto-luca
 *
 * Description:
 * This program demonstrates two fundamental sorting algorithms:
 * Bubble Sort and Insertion Sort. It starts with an unsorted array,
 * creates separate copies for each sorting technique, sorts them, and
 * then prints the sorted arrays to compare the results.
 *
 * Key Concepts:
 * - Bubble Sort: Repeatedly stepping through the list, comparing adjacent
 *   elements and swapping them if they are in the wrong order.
 * - Insertion Sort: Building the final sorted array one element at a time by inserting
 *   each item into its proper position.
 * - Array manipulation, iteration, and modular function design.
 */

#include <stdio.h>

// Function: bubbleSort
// --------------------
// Sorts an array using the bubble sort algorithm.
// Parameters:
//   arr - the array to be sorted
//   n   - the number of elements in the array
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    // Outer loop controls the number of passes through the array.
    for (i = 0; i < n - 1; i++) {
        // Inner loop compares adjacent elements.
        for (j = 0; j < n - i - 1; j++) {
            // If the current element is greater than the next element, swap them.
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];         // Store current element temporarily.
                arr[j] = arr[j + 1];     // Move the next element to the current position.
                arr[j + 1] = temp;       // Place the stored element in the next position.
            }
        }
    }
}

// Function: insertionSort
// -----------------------
// Sorts an array using the insertion sort algorithm.
// Parameters:
//   arr - the array to be sorted
//   n   - the number of elements in the array
void insertionSort(int arr[], int n) {
    int i, key, j;
    // Start from the second element, assuming that the first element is already sorted.
    for (i = 1; i < n; i++) {
        key = arr[i];   // The element to be inserted into the sorted portion.
        j = i - 1;
        // Move elements of the sorted portion that are greater than the key to one position ahead.
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];  // Shift element to the right.
            j = j - 1;
        }
        // Insert the key into its correct position.
        arr[j + 1] = key;
    }
}

// Function: printArray
// --------------------
// Helper function to print the elements of an array.
// Parameters:
//   arr - the array to print
//   n   - the number of elements in the array
void printArray(const int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void) {
    // An unsorted array for demonstration.
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // Create two copies of the original array for separate sorting methods.
    int bubbleArr[n], insertionArr[n];
    for (int i = 0; i < n; i++) {
        bubbleArr[i] = arr[i];
        insertionArr[i] = arr[i];
    }
    
    // Display the original unsorted array.
    printf("Original Array:\n");
    printArray(arr, n);
    
    // Sort the array using Bubble Sort and display the result.
    bubbleSort(bubbleArr, n);
    printf("Sorted Array using Bubble Sort:\n");
    printArray(bubbleArr, n);
    
    // Sort the array using Insertion Sort and display the result.
    insertionSort(insertionArr, n);
    printf("Sorted Array using Insertion Sort:\n");
    printArray(insertionArr, n);
    
    // End of the program.
    return 0;
}
