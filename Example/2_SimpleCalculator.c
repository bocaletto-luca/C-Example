/*
 * Project 2: Simple Calculator
 * Author: Bocaletto Luca
 * Date: 2025-06-22
 *
 * Description:
 * This program functions as a simple calculator capable of performing basic 
 * arithmetic operations: addition, subtraction, multiplication, and division.
 * It prompts the user for two numbers and an operator, then computes and displays the result.
 *
 * Key Concepts:
 * - Standard input/output using scanf() and printf()
 * - Conditional statements (if/else) for operation selection
 * - Basic error checking (e.g., preventing division by zero)
 */

#include <stdio.h>  // Standard I/O library for input and output functions

int main(void) {
    // Declare variables to store two numeric inputs and the result.
    double num1, num2, result;
    
    // Declare a variable to store the arithmetic operator.
    char operator;

    // Prompt the user to enter the first number.
    printf("Enter first number: ");
    scanf("%lf", &num1);  // Read a floating-point number from the user

    // Prompt the user to enter an operator.
    // The leading space in " %c" helps to skip any leftover whitespace.
    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &operator);

    // Prompt the user to enter the second number.
    printf("Enter second number: ");
    scanf("%lf", &num2);

    // Use conditional statements to perform the appropriate arithmetic operation based on the operator.
    if (operator == '+') {
        // Addition operation
        result = num1 + num2;
        printf("%.2lf + %.2lf = %.2lf\n", num1, num2, result);
    } else if (operator == '-') {
        // Subtraction operation
        result = num1 - num2;
        printf("%.2lf - %.2lf = %.2lf\n", num1, num2, result);
    } else if (operator == '*') {
        // Multiplication operation
        result = num1 * num2;
        printf("%.2lf * %.2lf = %.2lf\n", num1, num2, result);
    } else if (operator == '/') {
        // Division operation: check for division by zero.
        if (num2 == 0) {
            // Print an error message if num2 is zero.
            printf("Error: Division by zero is not allowed.\n");
        } else {
            result = num1 / num2;
            printf("%.2lf / %.2lf = %.2lf\n", num1, num2, result);
        }
    } else {
        // Print an error message for an unrecognized operator.
        printf("Error: Unknown operator '%c'\n", operator);
    }

    // Return 0 to indicate that the program executed successfully.
    return 0;
}
