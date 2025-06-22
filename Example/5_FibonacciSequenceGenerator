/*
 * Project 5: Fibonacci Sequence Generator
 * Author: Bocaletto Luca
 * Date: 2025-06-22
 * GitHub: bocaletto-luca
 *
 * Description:
 * This program generates the Fibonacci sequence up to a user-specified number
 * of terms. The Fibonacci sequence starts with 0 and 1, and each subsequent
 * term is the sum of the two preceding ones.
 *
 * Key Concepts:
 * - Using loops (for loop) to generate sequences.
 * - Basic arithmetic operations for computing Fibonacci numbers.
 * - Input validation to ensure a positive number of terms.
 */

#include <stdio.h>

int main(void) {
    int numTerms;            // Variable to store the number of terms for Fibonacci sequence
    
    // Prompt the user to enter how many Fibonacci terms to generate.
    printf("Enter the number of Fibonacci terms to generate: ");
    scanf("%d", &numTerms);

    // Validate that the user entered a positive number.
    if (numTerms <= 0) {
        printf("Error: Please enter a positive integer.\n");
        return 1;  // Return non-zero value to indicate an error.
    }

    // Special case: if only one term is requested.
    if (numTerms == 1) {
        printf("Fibonacci sequence with 1 term:\n0\n");
        return 0;
    }
    
    // Initialize the first two Fibonacci numbers.
    // Using the 'long long' data type to accommodate larger numbers.
    long long previous = 0;  // The first term of the sequence.
    long long current = 1;   // The second term of the sequence.

    // Display the initial part of the sequence.
    printf("Fibonacci sequence with %d terms:\n", numTerms);
    printf("%lld, %lld", previous, current);

    // Generate the remaining Fibonacci terms up to the specified number.
    for (int i = 3; i <= numTerms; ++i) {
        long long next = previous + current;  // Calculate the next term.
        printf(", %lld", next);                // Output the next term.
        previous = current;                     // Update 'previous' to the current term.
        current = next;                         // Update 'current' to the newly calculated term.
    }

    // End the output with a newline for clean formatting.
    printf("\n");

    // Return 0 to indicate successful execution of the program.
    return 0;
}
