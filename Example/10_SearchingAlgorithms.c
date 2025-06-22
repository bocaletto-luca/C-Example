/*
 * Project 10: Searching Algorithms: Linear and Binary Search
 * Author: Bocaletto Luca
 * Date: 2025-06-22
 * GitHub: bocaletto-luca
 *
 * Description:
 * This program demonstrates two search algorithms:
 * - Linear Search: Sequentially searches each element until the target is found.
 * - Binary Search: Efficiently divides the sorted array to locate the target.
 *
 * The program prompts the user to enter a target value and then performs both searches on a sample array.
 *
 * Key Concepts:
 * - Iterating over arrays and condition checks.
 * - Understanding the difference between unsorted (linear) and sorted (binary) search requirements.
 * - Handling edge cases where the target is not present.
 */

#include <stdio.h>

/*
 * Function: linearSearch
 * ----------------------
 * Searches for a target value in an array using linear (sequential) search.
 *
 * arr:    The array in which to search.
 * n:      The number of elements in the array.
 * target: The value to search for.
 *
 * returns: The index of the target if found; otherwise, -1.
 */
int linearSearch(int arr[], int n, int target) {
    // Iterate through each element of the array.
    for (int i = 0; i < n; i++) {
        // Check if the current element matches the target.
        if (arr[i] == target) {
            return i; // Target found at index i.
        }
    }
    return -1; // Target not found.
}

/*
 * Function: binarySearch
 * ----------------------
 * Searches for a target value in a sorted array using binary search.
 *
 * arr:    The sorted array in which to search.
 * n:      The number of elements in the array.
 * target: The value to search for.
 *
 * returns: The index of the target if found; otherwise, -1.
 */
int binarySearch(int arr[], int n, int target) {
    int low = 0;             // Lower bound of the search interval.
    int high = n - 1;        // Upper bound of the search interval.
    
    // Continue searching while the interval is valid.
    while (low <= high) {
        // Calculate the mid index to avoid potential overflow.
        int mid = low + (high - low) / 2;
        
        // If the target is at mid, we've found it.
        if (arr[mid] == target) {
            return mid;
        }
        
        // If the target is greater than the mid element, discard the left half.
        if (arr[mid] < target) {
            low = mid + 1;
        } else {
            // Otherwise, discard the right half.
            high = mid - 1;
        }
    }
    return -1;  // Target not found in the array.
}

int main(void) {
    // Define a sorted array for demonstration purposes.
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements in the array.
    
    int target;  // Variable to store the user's target value.
    printf("Enter the target value to search: ");
    scanf("%d", &target);  // Read the target value from the user.

    // Perform Linear Search.
    int linearResult = linearSearch(arr, n, target);
    if (linearResult != -1) {
        printf("Linear Search: Target %d found at index %d.\n", target, linearResult);
    } else {
        printf("Linear Search: Target %d not found in the array.\n", target);
    }
    
    // Perform Binary Search, which requires that the array is sorted.
    int binaryResult = binarySearch(arr, n, target);
    if (binaryResult != -1) {
        printf("Binary Search: Target %d found at index %d.\n", target, binaryResult);
    } else {
        printf("Binary Search: Target %d not found in the array.\n", target);
    }
    
    // Return 0 to indicate successful program termination.
    return 0;
}
