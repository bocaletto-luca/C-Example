/*
 * Project 12: Basic Banking System Simulation
 * Author: Bocaletto Luca
 * Date: 2025-06-22
 * GitHub: bocaletto-luca
 *
 * Description:
 * This program simulates a basic banking system that allows users to:
 * - Create an account with a unique account number, account holder name, and initial balance.
 * - Deposit money into an existing account.
 * - Withdraw money from an account (after verifying sufficient funds).
 * - Check account details and balance.
 *
 * Key Concepts:
 * - Use of structs to represent account data.
 * - Persistent storage with file I/O using a binary file ("accounts.dat").
 * - Menu-driven interface for user interaction.
 * - Error checking and basic validation in file operations.
 */

#include <stdio.h>
#include <stdlib.h>

// Define the file name for storing account information.
#define FILENAME "accounts.dat"

// Define the Account structure used to store account data.
typedef struct {
    int accountNumber;       // Unique account identifier.
    char name[50];           // Account holder's name.
    double balance;          // Current account balance.
} Account;

// Function: createAccount
// -----------------------
// Prompts the user for new account details and saves the record to the file.
void createAccount() {
    Account account;
    
    // Prompt user for account information.
    printf("Enter account number: ");
    scanf("%d", &account.accountNumber);
    
    printf("Enter account holder name: ");
    scanf(" %[^\n]s", account.name); // Read full name including spaces.
    
    printf("Enter initial balance: ");
    scanf("%lf", &account.balance);
    
    // Open the file in append binary mode.
    FILE *fp = fopen(FILENAME, "ab");
    if (fp == NULL) {
        perror("Error opening file for account creation");
        return;
    }
    
    // Write the account record to the file.
    fwrite(&account, sizeof(Account), 1, fp);
    fclose(fp);
    
    printf("Account created successfully.\n");
}

// Function: depositMoney
// ----------------------
// Deposits a specified amount into an existing account identified by its account number.
void depositMoney() {
    int accNo;
    double amount;
    
    // Read target account number and deposit amount.
    printf("Enter account number: ");
    scanf("%d", &accNo);
    printf("Enter deposit amount: ");
    scanf("%lf", &amount);
    
    // Open the file in read-update binary mode.
    FILE *fp = fopen(FILENAME, "rb+");
    if (fp == NULL) {
        perror("Error opening file for deposit");
        return;
    }
    
    Account account;
    int found = 0;
    
    // Iterate through the file to locate the account.
    while (fread(&account, sizeof(Account), 1, fp) == 1) {
        if (account.accountNumber == accNo) {
            // Update the account balance.
            account.balance += amount;
            
            // Move file pointer back to overwrite the current record.
            fseek(fp, -sizeof(Account), SEEK_CUR);
            fwrite(&account, sizeof(Account), 1, fp);
            found = 1;
            break;
        }
    }
    
    fclose(fp);
    
    // Provide feedback to the user.
    if (found) {
        printf("Deposit successful. New balance: %.2lf\n", account.balance);
    } else {
        printf("Account not found.\n");
    }
}

// Function: withdrawMoney
// -----------------------
// Withdraws a specified amount from an account after verifying sufficient funds.
void withdrawMoney() {
    int accNo;
    double amount;
    
    // Read target account number and withdrawal amount.
    printf("Enter account number: ");
    scanf("%d", &accNo);
    printf("Enter withdrawal amount: ");
    scanf("%lf", &amount);
    
    // Open the file in read-update binary mode.
    FILE *fp = fopen(FILENAME, "rb+");
    if (fp == NULL) {
        perror("Error opening file for withdrawal");
        return;
    }
    
    Account account;
    int found = 0;
    
    // Search for the account.
    while (fread(&account, sizeof(Account), 1, fp) == 1) {
        if (account.accountNumber == accNo) {
            // Check for sufficient funds.
            if (amount > account.balance) {
                printf("Insufficient funds. Withdrawal aborted.\n");
                fclose(fp);
                return;
            }
            
            // Deduct the withdrawal amount.
            account.balance -= amount;
            
            // Reposition file pointer and update the record.
            fseek(fp, -sizeof(Account), SEEK_CUR);
            fwrite(&account, sizeof(Account), 1, fp);
            found = 1;
            break;
        }
    }
    
    fclose(fp);
    
    // Show the result of the operation.
    if (found) {
        printf("Withdrawal successful. New balance: %.2lf\n", account.balance);
    } else {
        printf("Account not found.\n");
    }
}

// Function: checkBalance
// ----------------------
// Displays the account details and current balance for a given account number.
void checkBalance() {
    int accNo;
    
    // Read the account number from the user.
    printf("Enter account number: ");
    scanf("%d", &accNo);
    
    // Open the file in binary read mode.
    FILE *fp = fopen(FILENAME, "rb");
    if (fp == NULL) {
        perror("Error opening file for reading account details");
        return;
    }
    
    Account account;
    int found = 0;
    
    // Search the file for the specified account.
    while (fread(&account, sizeof(Account), 1, fp) == 1) {
        if (account.accountNumber == accNo) {
            // Display account information.
            printf("Account Number: %d\n", account.accountNumber);
            printf("Account Holder: %s\n", account.name);
            printf("Balance: %.2lf\n", account.balance);
            found = 1;
            break;
        }
    }
    
    fclose(fp);
    
    if (!found) {
        printf("Account not found.\n");
    }
}

// Main function: Displays the menu and processes user input.
int main(void) {
    int choice;
    
    while (1) {
        // Print the menu options.
        printf("\n--- Basic Banking System Menu ---\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        // Execute actions based on user's selection.
        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                depositMoney();
                break;
            case 3:
                withdrawMoney();
                break;
            case 4:
                checkBalance();
                break;
            case 5:
                printf("Exiting system. Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}
