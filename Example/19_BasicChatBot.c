/*
 * Project 19: Basic Chatbot Program
 * Author: Bocaletto Luca
 * Date: 2025-06-22
 * GitHub: bocaletto-luca
 *
 * Description:
 * This program implements a simple text-based chatbot that listens to user input,
 * processes it using basic pattern matching, and responds with predetermined answers.
 * It continues the conversation until the user types "bye" to exit the chat.
 *
 * Key Concepts:
 * - String parsing and pattern matching (using functions like strcmp() and strstr()).
 * - Loop constructs for sustaining interactive conversation.
 * - Conditional logic to select appropriate responses based on input.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(void) {
    char input[256];  // Buffer to store user input.

    // Welcoming the user.
    printf("Chatbot: Hello, I'm your friendly chatbot. Type 'bye' to exit.\n");

    // Main conversation loop.
    while (1) {
        printf("You: ");
        // Read user input from the terminal.
        if (fgets(input, sizeof(input), stdin) == NULL) {
            // Handle potential input errors.
            printf("Chatbot: Error reading input. Exiting.\n");
            break;
        }
        
        // Remove the trailing newline character, if present.
        input[strcspn(input, "\n")] = '\0';

        // Convert the input to lowercase for easier matching.
        for (int i = 0; input[i] != '\0'; i++) {
            input[i] = tolower(input[i]);
        }

        // Check if the user wants to exit the conversation.
        if (strcmp(input, "bye") == 0) {
            printf("Chatbot: Goodbye! Have a nice day.\n");
            break;
        }

        // Respond based on pattern matching using strstr() and strcmp().
        if (strstr(input, "hello") != NULL) {
            printf("Chatbot: Hello there! How can I help you today?\n");
        } else if (strstr(input, "how are you") != NULL) {
            printf("Chatbot: I'm just a program, but I'm doing fine! How about you?\n");
        } else if (strstr(input, "what is your name") != NULL) {
            printf("Chatbot: I'm a basic chatbot created by Bocaletto Luca.\n");
        } else if (strstr(input, "weather") != NULL) {
            printf("Chatbot: I don't have real-time weather data, but it's always a good day for coding!\n");
        } else {
            // Default response for unrecognized inputs.
            printf("Chatbot: I'm not sure I understand. Can you please rephrase your question?\n");
        }
    }

    return 0;
}
