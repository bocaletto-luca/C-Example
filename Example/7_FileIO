/*
 * Project 7: File I/O: Read and Write
 * Author: Bocaletto Luca
 * Date: 2025-06-22
 * GitHub: bocaletto-luca
 *
 * Description:
 * This program demonstrates basic file input and output operations in C.
 * It prompts the user to enter a line of text, writes that text to a file,
 * and then reads the contents of the file to display them on the console.
 *
 * Key Concepts:
 * - Opening files for writing and reading using fopen().
 * - Writing to a file using fprintf().
 * - Reading from a file using fgets().
 * - Error checking for file operations.
 * - Closing files with fclose() to ensure proper resource management.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // Define the file name to be used.
    const char *filename = "output.txt";
    
    // Buffer to store the user's input.
    char userInput[256];

    // Prompt the user to enter a line of text.
    printf("Enter a line of text to write to the file:\n");
    if (fgets(userInput, sizeof(userInput), stdin) == NULL) {
        // If reading fails, output an error message and exit.
        perror("Error reading input");
        return 1;
    }

    // Open the file in write mode ("w").
    // This will create the file if it doesn't exist or truncate it if it does.
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        // If the file cannot be opened for writing, output an error and exit.
        perror("Error opening file for writing");
        return 1;
    }
    
    // Write the user input to the file.
    // Using fprintf() to format and write the string.
    fprintf(file, "%s", userInput);
    
    // Close the file to save changes.
    fclose(file);

    // Reopen the file in read mode ("r") to read back the content.
    file = fopen(filename, "r");
    if (file == NULL) {
        // If the file cannot be opened for reading, output an error and exit.
        perror("Error opening file for reading");
        return 1;
    }

    // Buffer to temporarily hold each line read from the file.
    char fileBuffer[256];
    
    // Display the content read from the file.
    printf("Content read from file:\n");
    while (fgets(fileBuffer, sizeof(fileBuffer), file) != NULL) {
        // Print each line retrieved from the file.
        printf("%s", fileBuffer);
    }
    
    // Close the file after reading.
    fclose(file);
    
    // End the program successfully.
    return 0;
}
