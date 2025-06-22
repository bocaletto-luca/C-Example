/*
 * Project 4: Random Number Guessing Game
 * Author: Bocaletto Luca
 * Date: 2025-06-22
 * GitHub: bocaletto-luca
 *
 * Description:
 * This program randomly selects an integer between 1 and 100 and
 * prompts the user to guess the number. After each guess, the program
 * tells the user if the guess is too low or too high until the correct
 * number is guessed.
 *
 * Key Concepts:
 * - Random number generation using rand() and seeding with srand() and time(NULL)
 * - Using loops (do-while) for repeated user input until a condition is met
 * - Conditional statements to provide user feedback
 */

#include <stdio.h>    // Standard Input/Output for printf() and scanf()
#include <stdlib.h>   // Standard Library for rand(), srand()
#include <time.h>     // Time library for time() to seed the random number generator

int main(void) {
    int secretNumber; // Variable to store the randomly generated number
    int guess;        // Variable to store the user's guess

    // Seed the random number generator with the current time.
    // This ensures that a different sequence of random numbers is generated each time the program is run.
    srand((unsigned int) time(NULL));

    // Generate a random number between 1 and 100.
    // rand() returns a value between 0 and RAND_MAX, so we use modulo 100 and add 1 to shift the range to 1-100.
    secretNumber = (rand() % 100) + 1;

    // Inform the user about the game.
    printf("Welcome to the Random Number Guessing Game!\n");
    printf("I have selected a random number between 1 and 100.\n");
    printf("Try to guess the number!\n");

    // Continue prompting the user until they guess the correct number.
    do {
        // Request the user to enter a guess.
        printf("Enter your guess: ");
        scanf("%d", &guess);

        // Check if the guess is lower than, higher than, or equal to the secret number.
        if (guess < secretNumber) {
            printf("Too low! Try again.\n");
        } else if (guess > secretNumber) {
            printf("Too high! Try again.\n");
        } else {
            // When the guess is correct, congratulate the user.
            printf("Congratulations! You guessed the number %d correctly!\n", secretNumber);
        }
    } while (guess != secretNumber);  // The loop continues until the correct guess is made.

    // Return 0 to indicate that the program ended successfully.
    return 0;
}
