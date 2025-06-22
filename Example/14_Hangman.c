/*
 * Project 14: Hangman Game
 * Author: Bocaletto Luca
 * Date: 2025-06-22
 * GitHub: bocaletto-luca
 *
 * Description:
 * This program implements the classic Hangman game. A secret word is randomly
 * selected from a predefined word list. The player attempts to guess the word 
 * by suggesting letters. Correct guesses reveal all occurrences of that letter 
 * in the word, while incorrect guesses increase the wrong guess count. The game 
 * continues until the word is completely guessed or the maximum number of 
 * incorrect guesses is reached.
 *
 * Key Concepts:
 * - String handling and array manipulations.
 * - Random selection from an array of strings.
 * - User input and validation.
 * - A game loop with win and loss conditions.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>  // For converting characters to lowercase

#define MAX_TRIES 6  // Maximum number of allowed incorrect guesses

/*
 * Function: alreadyGuessed
 * --------------------------
 * Checks whether a given letter has already been guessed.
 *
 * guessedLetters: An array of guessed letters.
 * numGuessed:     The number of letters already guessed.
 * letter:         The current letter to check.
 *
 * returns: 1 (true) if the letter was already guessed; 0 (false) otherwise.
 */
int alreadyGuessed(char guessedLetters[], int numGuessed, char letter) {
    for (int i = 0; i < numGuessed; i++) {
        if (guessedLetters[i] == letter) {
            return 1;
        }
    }
    return 0;
}

/*
 * Function: updateMaskedWord
 * ---------------------------
 * Updates the masked word by revealing the positions where the guessed letter
 * occurs in the secret word.
 *
 * secret: The secret word.
 * masked: The current masked representation of the secret word.
 * guess:  The letter that was guessed correctly.
 */
void updateMaskedWord(const char secret[], char masked[], char guess) {
    int len = strlen(secret);
    for (int i = 0; i < len; i++) {
        if (secret[i] == guess) {
            masked[i] = guess;
        }
    }
}

int main(void) {
    // Define a list of possible secret words.
    const char *wordList[] = {"apple", "banana", "cherry", "orange", "grape", "mango"};
    int wordCount = sizeof(wordList) / sizeof(wordList[0]);

    // Seed the random number generator for different outcomes on each run.
    srand((unsigned int) time(NULL));

    // Randomly select a secret word from the word list.
    const char *secret = wordList[rand() % wordCount];
    int secretLen = strlen(secret);

    // Create a masked version of the secret word (e.g., "apple" becomes "_____").
    char masked[secretLen + 1];
    for (int i = 0; i < secretLen; i++) {
        masked[i] = '_';
    }
    masked[secretLen] = '\0';  // Null-terminate the string.

    // Array to store letters that have been guessed.
    char guessedLetters[26] = {0};
    int numGuessed = 0;

    int wrongGuesses = 0;  // Counter for incorrect guesses.

    printf("Welcome to Hangman!\n");
    printf("Try to guess the secret word, one letter at a time.\n");
    printf("You are allowed a maximum of %d wrong guesses.\n", MAX_TRIES);

    // Main game loop: runs until the player guesses the word or runs out of tries.
    while (wrongGuesses < MAX_TRIES && strcmp(secret, masked) != 0) {
        // Display current game state.
        printf("\nSecret Word: %s\n", masked);
        printf("Wrong guesses: %d/%d\n", wrongGuesses, MAX_TRIES);
        if (numGuessed > 0) {
            printf("Guessed letters: ");
            for (int i = 0; i < numGuessed; i++) {
                printf("%c ", guessedLetters[i]);
            }
            printf("\n");
        }

        // Prompt the user for a single-letter guess.
        char guessInput[100];
        char guess;
        printf("Enter your guess (a single letter): ");
        scanf("%s", guessInput);
        guess = tolower(guessInput[0]);  // Convert to lowercase for consistency.

        // Check if the letter has already been guessed.
        if (alreadyGuessed(guessedLetters, numGuessed, guess)) {
            printf("You've already guessed the letter '%c'. Try a different letter.\n", guess);
            continue;
        }

        // Store the new guess.
        guessedLetters[numGuessed++] = guess;

        // Determine if the guess is part of the secret word.
        if (strchr(secret, guess) != NULL) {
            // Correct guess: update the masked representation.
            updateMaskedWord(secret, masked, guess);
            printf("Good guess!\n");
        } else {
            // Incorrect guess: increment the wrong guess counter.
            printf("Sorry, '%c' is not in the word.\n", guess);
            wrongGuesses++;
        }
    }

    // Outcome evaluation.
    if (strcmp(secret, masked) == 0) {
        printf("\nCongratulations! You guessed the word '%s' correctly!\n", secret);
    } else {
        printf("\nGame Over! You've reached the maximum number of wrong guesses.\n");
        printf("The secret word was: '%s'\n", secret);
    }

    return 0;
}
