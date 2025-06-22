/*
 * Project 16: Student Record Management System
 * Author: Bocaletto Luca
 * Date: 2025-06-22
 * GitHub: bocaletto-luca
 *
 * Description:
 * This program implements a student record management system that allows users
 * to perform the following operations:
 *   - Create a new student record.
 *   - List all existing student records.
 *   - Search for a student record by ID.
 *   - Update an existing student record.
 *   - Delete a student record.
 *
 * Records are stored persistently in a binary file ("students.dat"). Each record is
 * represented as a structure containing the student's ID, name, and grade.
 *
 * Key Concepts:
 * - Structures to represent student data.
 * - File I/O operations for persistent storage.
 * - A menu-driven interface using a switch statement for navigation.
 * - Proper error handling and file management.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "students.dat"

// Structure to represent a student record.
typedef struct {
    int id;             // Unique student ID.
    char name[50];      // Student's name.
    float grade;        // Student's grade.
} Student;

// Function: createStudent
// -----------------------
// Prompts the user for student details and appends a new record to the file.
void createStudent() {
    Student s;
    FILE *fp = fopen(FILENAME, "ab");  // Open file in append binary mode.
    if (fp == NULL) {
        perror("Unable to open file for appending");
        return;
    }
    printf("Enter student ID: ");
    scanf("%d", &s.id);
    printf("Enter student name: ");
    scanf(" %[^\n]s", s.name);  // Reads full name including spaces.
    printf("Enter student grade: ");
    scanf("%f", &s.grade);
    
    // Save the new student record.
    fwrite(&s, sizeof(Student), 1, fp);
    fclose(fp);
    printf("Student record added successfully.\n");
}

// Function: listStudents
// ----------------------
// Reads and displays all student records from the file.
void listStudents() {
    FILE *fp = fopen(FILENAME, "rb");  // Open file in read binary mode.
    if (fp == NULL) {
        perror("Unable to open file for reading");
        return;
    }
    Student s;
    printf("\n--- Student Records ---\n");
    while (fread(&s, sizeof(Student), 1, fp)) {
        printf("ID: %d, Name: %s, Grade: %.2f\n", s.id, s.name, s.grade);
    }
    fclose(fp);
}

// Function: searchStudent
// -----------------------
// Searches for and displays a student record by student ID.
void searchStudent() {
    int id;
    printf("Enter student ID to search: ");
    scanf("%d", &id);
    
    FILE *fp = fopen(FILENAME, "rb");
    if (fp == NULL) {
        perror("Unable to open file for search");
        return;
    }
    
    Student s;
    int found = 0;
    while (fread(&s, sizeof(Student), 1, fp)) {
        if (s.id == id) {
            printf("Record found: ID: %d, Name: %s, Grade: %.2f\n", s.id, s.name, s.grade);
            found = 1;
            break;
        }
    }
    fclose(fp);
    
    if (!found) {
        printf("No record found with student ID %d.\n", id);
    }
}

// Function: updateStudent
// -----------------------
// Updates a student record by searching for it via student ID and then modifying its data.
void updateStudent() {
    int id;
    printf("Enter student ID to update: ");
    scanf("%d", &id);
    
    FILE *fp = fopen(FILENAME, "rb+");  // Open file in read/update mode.
    if (fp == NULL) {
        perror("Unable to open file for updating");
        return;
    }
    
    Student s;
    int found = 0;
    while (fread(&s, sizeof(Student), 1, fp)) {
        if (s.id == id) {
            printf("Current Record - ID: %d, Name: %s, Grade: %.2f\n", s.id, s.name, s.grade);
            // Prompt for new details.
            printf("Enter new name: ");
            scanf(" %[^\n]s", s.name);
            printf("Enter new grade: ");
            scanf("%f", &s.grade);
            // Move the file pointer back one record and update it.
            fseek(fp, -sizeof(Student), SEEK_CUR);
            fwrite(&s, sizeof(Student), 1, fp);
            found = 1;
            printf("Record updated successfully.\n");
            break;
        }
    }
    fclose(fp);
    
    if (!found) {
        printf("No record found with student ID %d.\n", id);
    }
}

// Function: deleteStudent
// -----------------------
// Deletes a student record by copying all records except the one to be deleted into
// a temporary file, then replacing the original file with this file.
void deleteStudent() {
    int id;
    printf("Enter student ID to delete: ");
    scanf("%d", &id);
    
    FILE *fp = fopen(FILENAME, "rb");
    if (fp == NULL) {
        perror("Unable to open file for deletion");
        return;
    }
    
    FILE *temp = fopen("temp.dat", "wb");
    if (temp == NULL) {
        perror("Unable to open temporary file for writing");
        fclose(fp);
        return;
    }
    
    Student s;
    int found = 0;
    // Copy every record except the one to delete.
    while (fread(&s, sizeof(Student), 1, fp)) {
        if (s.id == id) {
            found = 1;
            continue;
        }
        fwrite(&s, sizeof(Student), 1, temp);
    }
    fclose(fp);
    fclose(temp);
    
    if (found) {
        // Replace the original file with the temporary file.
        remove(FILENAME);
        rename("temp.dat", FILENAME);
        printf("Student record with ID %d deleted successfully.\n", id);
    } else {
        remove("temp.dat");
        printf("No record found with student ID %d.\n", id);
    }
}

// Main function: Displays a menu and processes user input.
int main(void) {
    int choice;
    while (1) {
        printf("\n--- Student Record Management System ---\n");
        printf("1. Create Student Record\n");
        printf("2. List All Student Records\n");
        printf("3. Search Student Record\n");
        printf("4. Update Student Record\n");
        printf("5. Delete Student Record\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                createStudent();
                break;
            case 2:
                listStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                updateStudent();
                break;
            case 5:
                deleteStudent();
                break;
            case 6:
                printf("Exiting Student Record Management System.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
