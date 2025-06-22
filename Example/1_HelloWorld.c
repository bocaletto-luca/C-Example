/*
 * Project 1: Hello World Program
 * Author: Your Name
 * Date: YYYY-MM-DD
 *
 * Description:
 * This simple program demonstrates the fundamental structure of a C program.
 * It prints the classic "Hello, World!" message to the console. This example
 * is designed for beginners who want to understand the entry point of a C program,
 * the inclusion of standard libraries, and the basic output function.
 *
 * Key Concepts:
 * - Preprocessor directives and the inclusion of the standard I/O library.
 * - The `main()` function as the entry point of the program.
 * - Using `printf()` to display output on the screen.
 * - Returning 0 to indicate successful program termination.
 */

#include <stdio.h>  // Include the Standard Input/Output library for printing output

// The main function: the entry point of execution for every C program.
int main(void) {
    // Print the "Hello, World!" string to the console.
    // The "\n" character ensures a newline after the text is printed.
    printf("Hello, World!\n");

    // Return 0 from main to indicate that the program ended successfully.
    return 0;
}
