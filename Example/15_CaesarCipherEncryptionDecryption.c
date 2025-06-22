/*
 * Project 15: Caesar Cipher for Encryption/Decryption
 * Author: Bocaletto Luca
 * Date: 2025-06-22
 * GitHub: bocaletto-luca
 *
 * Description:
 * This program implements the classic Caesar cipher to encrypt and decrypt text.
 * The cipher shifts each letter by a specified number of positions in the alphabet.
 * For example, with a shift of 3, 'A' becomes 'D', 'B' becomes 'E', etc.
 * Non-alphabetical characters remain unchanged.
 *
 * Key Concepts:
 * - ASCII arithmetic for letter shifting.
 * - Handling both uppercase and lowercase letters.
 * - Keeping non-letter characters intact.
 * - Reversibility: decryption is achieved by applying a negative shift.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function: caesarCipher
// ----------------------
// Applies a Caesar cipher shift to the given text.
// Parameters:
//   text  - The input string to transform (in-place modification).
//   shift - The number of positions to shift each letter by.
//           A positive value encrypts the text; a negative value decrypts it.
void caesarCipher(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        char ch = text[i];
        // Check if the character is an alphabet letter.
        if (isalpha(ch)) {
            // Determine the offset based on whether the character is uppercase or lowercase.
            char offset = isupper(ch) ? 'A' : 'a';
            // Apply the shift using modulo arithmetic to wrap around the alphabet.
            // The double modulo ensures a positive result even if the shift is negative.
            text[i] = ((ch - offset + shift) % 26 + 26) % 26 + offset;
        }
    }
}

int main(void) {
    char text[256]; // Buffer to store the input text.
    int choice;     // User's choice: 1 for encryption, 2 for decryption.
    int shift;      // Shift value for the cipher.

    // Display program header information.
    printf("Caesar Cipher Encryption/Decryption\n");
    printf("Author: Bocaletto Luca\n");
    printf("Date: 2025-06-22\n");
    printf("GitHub: bocaletto-luca\n\n");

    // Provide a simple menu for operation selection.
    printf("Choose an operation:\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);
    
    // Clear the newline left in the buffer after scanf.
    getchar();
    
    // Prompt the user to enter the text to be processed.
    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);
    // Remove the trailing newline character if present.
    text[strcspn(text, "\n")] = '\0';

    // Ask the user for the shift value (a positive integer).
    printf("Enter shift value (positive integer): ");
    scanf("%d", &shift);

    // For decryption, reverse the shift direction.
    if (choice == 2) {
        shift = -shift;
    }

    // Apply the Caesar cipher transformation to the input text.
    caesarCipher(text, shift);

    // Display the result based on the operation selected.
    if (choice == 1) {
        printf("Encrypted text: %s\n", text);
    } else if (choice == 2) {
        printf("Decrypted text: %s\n", text);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}
