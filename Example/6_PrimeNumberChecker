/*
 * Project 6: Prime Number Checker
 * Author: Bocaletto Luca
 * Date: 2025-06-22
 * GitHub: bocaletto-luca
 *
 * Description:
 * This program determines whether a given integer is prime.
 * It prompts the user to input an integer, then uses an optimized
 * algorithm to check for factors up to the square root of the integer.
 *
 * Key Concepts:
 * - Input validation, loops, and conditional statements in C.
 * - Optimizing a prime check by testing divisibility only up to sqrt(n).
 * - Using the math library for the square root function.
 */

#include <stdio.h>   // Standard Input/Output library for printf() and scanf()
#include <math.h>    // Math library for the sqrt() function

/*
 * Function: isPrime
 * -----------------
 * Checks whether a given integer n is a prime number.
 *
 * n: The integer to check.
 *
 * returns: 1 (true) if n is prime, 0 (false) otherwise.
 */
int isPrime(int n) {
    // Handle numbers less than or equal to 1. These cannot be prime.
    if (n <= 1) {
        return 0;
    }
    
    // 2 is the only even prime number.
    if (n == 2) {
        return 1;
    }
    
    // Even numbers greater than 2 are not prime.
    if (n % 2 == 0) {
        return 0;
    }
    
    // Test odd divisors from 3 up to the square root of n.
    int maxDivisor = (int) sqrt(n);
    for (int i = 3; i <= maxDivisor; i += 2) {
        // If n is divisible by any i, then n is not prime.
        if (n % i == 0) {
            return 0;
        }
    }
    
    // If no divisors were found, n is prime.
    return 1;
}

int main(void) {
    int number;  // Variable to store the user's integer input

    // Prompt the user to enter an integer.
    printf("Enter an integer: ");
    scanf("%d", &number);

    // Use the isPrime() function to check if the number is prime,
    // and output the corresponding message.
    if (isPrime(number)) {
        printf("%d is a prime number.\n", number);
    } else {
        printf("%d is not a prime number.\n", number);
    }

    // Return 0 to indicate successful termination of the program.
    return 0;
}
