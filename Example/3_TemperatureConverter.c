/*
 * Project 3: Temperature Converter
 * Author: Bocaletto Luca
 * Date: 2025-06-22
 * GitHub: bocaletto-luca
 *
 * Description:
 * This program converts temperature values between Celsius and Fahrenheit.
 * It prompts the user to choose the conversion type, then asks for the temperature,
 * performs the conversion using the appropriate formula, and finally outputs the result.
 *
 * Key Concepts:
 * - Using scanf() to handle user input.
 * - Conditional logic (if/else statements) to select the conversion type.
 * - Simple mathematical operations for temperature conversion.
 *
 * Conversion Formulas:
 * - Celsius to Fahrenheit: (C * 9/5) + 32
 * - Fahrenheit to Celsius: (F - 32) * 5/9
 */

#include <stdio.h>  // Standard I/O library for input and output functions

int main(void) {
    int conversionChoice;   // Variable to store the user's conversion choice
    double temperatureInput, temperatureOutput;  // Variables for input temperature and the converted output

    // Display the program header information for user clarity.
    printf("Temperature Converter\n");
    printf("---------------------\n");
    printf("Please select the conversion type:\n");
    printf("1: Celsius to Fahrenheit\n");
    printf("2: Fahrenheit to Celsius\n");
    printf("Enter your choice (1 or 2): ");
    
    // Read the conversion type choice from the user.
    scanf("%d", &conversionChoice);

    // Check the conversion type selected by the user.
    if (conversionChoice == 1) {
        // Celsius to Fahrenheit conversion:
        // Prompt user to enter the temperature in Celsius.
        printf("Enter temperature in Celsius: ");
        scanf("%lf", &temperatureInput);

        // Perform the conversion using the formula:
        // Fahrenheit = (Celsius * 9/5) + 32
        temperatureOutput = (temperatureInput * 9.0 / 5.0) + 32.0;
        
        // Display the result.
        printf("%.2lf Celsius = %.2lf Fahrenheit\n", temperatureInput, temperatureOutput);
    } else if (conversionChoice == 2) {
        // Fahrenheit to Celsius conversion:
        // Prompt user to enter the temperature in Fahrenheit.
        printf("Enter temperature in Fahrenheit: ");
        scanf("%lf", &temperatureInput);

        // Perform the conversion using the formula:
        // Celsius = (Fahrenheit - 32) * 5/9
        temperatureOutput = (temperatureInput - 32.0) * 5.0 / 9.0;
        
        // Display the result.
        printf("%.2lf Fahrenheit = %.2lf Celsius\n", temperatureInput, temperatureOutput);
    } else {
        // Handle invalid input for conversion selection.
        printf("Error: Invalid conversion type selected.\n");
    }

    // Return 0 to indicate successful program termination.
    return 0;
}
