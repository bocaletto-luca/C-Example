/*
 * Project 11: Singly Linked List Implementation
 * Author: Bocaletto Luca
 * Date: 2025-06-22
 * GitHub: bocaletto-luca
 *
 * Description:
 * This program implements a singly linked list where each node stores an integer.
 * It demonstrates fundamental operations such as:
 * - Insertion at the end of the list.
 * - Searching for a node by its key (data).
 * - Deleting a node by key.
 * - Printing the linked list.
 *
 * Key Concepts:
 * - Dynamic memory allocation using malloc() and proper deallocation via free().
 * - Structs and pointer manipulation to traverse and manage the list.
 * - Modular design: separate functions for insertion, deletion, search, and display.
 */

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list.
typedef struct Node {
    int data;              // Data stored in the node.
    struct Node* next;     // Pointer to the next node in the list.
} Node;

// Function: createNode
// --------------------
// Allocates and initializes a new node with the given data.
// Returns a pointer to the newly created node.
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));  // Allocate memory for the node.
    if (!newNode) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;  // Set the node's data.
    newNode->next = NULL;  // Initialize next pointer to NULL.
    return newNode;
}

// Function: insertAtEnd
// -----------------------
// Inserts a new node with the specified data at the end of the linked list.
// head: Double pointer to the head of the list.
// data: The integer value to insert.
void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);  // Create a new node.
    
    // If the list is empty, set the new node as the head.
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    // Traverse the list to find the last node.
    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    // Link the new node at the end of the list.
    current->next = newNode;
}

// Function: searchNode
// --------------------
// Searches for a node with a given key (data) in the linked list.
// Returns a pointer to the node if found; otherwise, returns NULL.
Node* searchNode(Node* head, int key) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            return current;  // Key found.
        }
        current = current->next;
    }
    return NULL;  // Key not found.
}

// Function: deleteNode
// --------------------
// Deletes the first occurrence of a node with the specified key from the list.
// head: Double pointer to the head of the list.
// key: The value of the node to delete.
void deleteNode(Node** head, int key) {
    Node* current = *head;
    Node* previous = NULL;
    
    // Check if the head node holds the key.
    if (current != NULL && current->data == key) {
        *head = current->next;  // Change the head.
        free(current);          // Free memory.
        return;
    }
    
    // Traverse the list keeping track of the previous node.
    while (current != NULL && current->data != key) {
        previous = current;
        current = current->next;
    }
    
    // If the key was not found in the list.
    if (current == NULL) {
        printf("Key %d not found in the list.\n", key);
        return;
    }
    
    // Unlink the node from the list.
    previous->next = current->next;
    free(current);  // Free memory of the deleted node.
}

// Function: printList
// -------------------
// Prints all the nodes in the linked list in sequence.
void printList(Node* head) {
    Node* current = head;
    printf("Linked List: ");
    while(current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");  // Indicates the end of the list.
}

// Main function demonstrating linked list operations.
int main(void) {
    Node* head = NULL;  // Start with an empty linked list.
    
    // Insert nodes into the list.
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);
    
    // Display the list after insertions.
    printList(head);
    
    // Search for a node with key 30.
    int keyToSearch = 30;
    Node* foundNode = searchNode(head, keyToSearch);
    if (foundNode) {
        printf("Node with key %d found.\n", keyToSearch);
    } else {
        printf("Node with key %d not found.\n", keyToSearch);
    }
    
    // Delete a node with key 20 and display the list.
    int keyToDelete = 20;
    printf("Deleting node with key %d.\n", keyToDelete);
    deleteNode(&head, keyToDelete);
    printList(head);
    
    // Attempt to delete a key that does not exist.
    keyToDelete = 100;
    deleteNode(&head, keyToDelete);
    
    // Free all nodes in the list to avoid memory leaks.
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
    
    return 0;
}
