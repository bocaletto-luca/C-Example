/*
 * Project 13: Tic Tac Toe Game
 * Author: Bocaletto Luca
 * Date: 2025-06-22
 * GitHub: bocaletto-luca
 *
 * Description:
 * This program implements a text-based Tic Tac Toe game on a 3x3 board.
 * Two players take turns entering their moves by specifying the row and column.
 * After each move, the game checks for a win (three in a row horizontally, vertically,
 * or diagonally) or a tie if the board is full.
 *
 * Key Concepts:
 * - 2D array manipulation for the game board.
 * - User input handling for move selection.
 * - Conditional checks to determine game state (win, tie, or continue playing).
 * - Alternating turn logic for two players.
 */

#include <stdio.h>

// Define the board size constant (3x3 board)
#define BOARD_SIZE 3

// Function: printBoard
// --------------------
// Prints the current state of the Tic Tac Toe board.
void printBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf(" ");
        for (int j = 0; j < BOARD_SIZE; j++) {
            // Print the cell value; if cell is empty, print a blank space.
            printf(" %c ", board[i][j] ? board[i][j] : ' ');
            if (j < BOARD_SIZE - 1) {
                printf("|");
            }
        }
        printf("\n");
        // Print horizontal separator between rows.
        if (i < BOARD_SIZE - 1) {
            printf(" ---+---+---\n");
        }
    }
    printf("\n");
}

// Function: checkWin
// ------------------
// Checks whether the current board has a winning configuration.
// Returns the winning marker ('X' or 'O') if a win is found; otherwise returns ' '.
char checkWin(char board[BOARD_SIZE][BOARD_SIZE]) {
    // Check rows for a win.
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] != '\0' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }
    // Check columns for a win.
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[0][j] != '\0' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return board[0][j];
        }
    }
    // Check main diagonal.
    if (board[0][0] != '\0' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    // Check secondary diagonal.
    if (board[0][2] != '\0' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }
    // No winner found.
    return ' ';
}

// Main function: Contains the game loop and handles user input and game progress.
int main(void) {
    // Initialize board with empty cells represented by '\0'.
    char board[BOARD_SIZE][BOARD_SIZE] = { { '\0' } };
    char currentPlayer = 'X'; // Player 1 starts with 'X'; Player 2 will be 'O'
    int moveCount = 0;        // Counter to detect tie (maximum 9 moves)

    printf("Tic Tac Toe Game\n");
    printf("Player 1: X, Player 2: O\n\n");
    
    // The game loop runs while there are moves left and no winner.
    while (moveCount < BOARD_SIZE * BOARD_SIZE) {
        printBoard(board);
        
        int row, col;
        // Prompt current player for move input.
        printf("Player %c, enter your move (row [1-3] and column [1-3]): ", currentPlayer);
        scanf("%d %d", &row, &col);
        
        // Convert 1-indexed input to 0-indexed array coordinates.
        row -= 1;
        col -= 1;
        
        // Validate the input coordinates.
        if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
            printf("Invalid move. Please choose row and column between 1 and 3.\n");
            continue;
        }
        
        // Check if the selected cell is already occupied.
        if (board[row][col] != '\0') {
            printf("Cell already occupied. Choose a different move.\n");
            continue;
        }
        
        // Place the current player's marker on the board.
        board[row][col] = currentPlayer;
        moveCount++;
        
        // Check if this move causes a win.
        char winner = checkWin(board);
        if (winner != ' ') {
            printBoard(board);
            printf("Congratulations! Player %c wins!\n", winner);
            break;
        }
        
        // If all moves are used with no winner, it's a tie.
        if (moveCount == BOARD_SIZE * BOARD_SIZE) {
            printBoard(board);
            printf("The game is a tie!\n");
            break;
        }
        
        // Switch turns: if current player is 'X', change to 'O', and vice versa.
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
    
    return 0;
}
