/*
 * Project 20: Binary Search Tree (BST) Implementation
 * Author: Bocaletto Luca
 * Date: 2025-06-22
 * GitHub: bocaletto-luca
 *
 * Description:
 * This program implements a binary search tree (BST) with the following operations:
 * - Insertion: Add new nodes while preserving the BST property, where all nodes in the left subtree
 *   contain values less than the parent node, and all nodes in the right subtree contain values greater.
 * - Searching: Locate a node with a specific value in the BST.
 * - Traversals:
 *   - In-order Traversal: Visits nodes in ascending order.
 *   - Pre-order Traversal: Visits the root before its subtrees.
 *   - Post-order Traversal: Visits the root after its subtrees.
 *
 * Key Concepts:
 * - Dynamic memory allocation using malloc().
 * - Recursion for tree operations.
 * - Maintaining the BST property during insertions and searches.
 */

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a BST node.
typedef struct Node {
    int data;              // Data stored in the node.
    struct Node* left;     // Pointer to the left child.
    struct Node* right;    // Pointer to the right child.
} Node;

// Function: createNode
// --------------------
// Allocates a new node with the given data and initializes its pointers to NULL.
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function: insert
// ----------------
// Recursively inserts a new value into the BST while preserving its properties.
// Parameters:
//   root - The root node of the BST (can be NULL for an empty tree).
//   data - The value to insert.
// Returns the new root of the BST.
Node* insert(Node* root, int data) {
    if (root == NULL) {
        // Found the correct position for insertion.
        return createNode(data);
    }
    if (data < root->data) {
        // Insert into the left subtree if the data is less than the current node's value.
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        // Insert into the right subtree if the data is greater than the current node's value.
        root->right = insert(root->right, data);
    }
    // Duplicate values are not inserted; return the unchanged node.
    return root;
}

// Function: searchNode
// --------------------
// Searches for a node with the specified value in the BST.
// Parameters:
//   root - The root node of the BST.
//   data - The value to search for.
// Returns a pointer to the node if found; otherwise, returns NULL.
Node* searchNode(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return searchNode(root->left, data);
    } else {
        return searchNode(root->right, data);
    }
}

// Function: inorderTraversal
// --------------------------
// Performs an in-order traversal (left, root, right) of the BST and prints the node values.
// This traversal prints the values in sorted order.
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function: preorderTraversal
// ---------------------------
// Performs a pre-order traversal (root, left, right) of the BST and prints the node values.
void preorderTraversal(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Function: postorderTraversal
// ----------------------------
// Performs a post-order traversal (left, right, root) of the BST and prints the node values.
void postorderTraversal(Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Main function: Demonstrates BST operations.
int main(void) {
    Node* root = NULL; // Start with an empty BST.
    
    // Insert elements into the BST.
    int elements[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(elements) / sizeof(elements[0]);
    for (int i = 0; i < n; i++) {
        root = insert(root, elements[i]);
    }
    
    // Display the BST using different traversals.
    printf("In-order Traversal (Sorted Order):\n");
    inorderTraversal(root);
    printf("\n");
    
    printf("Pre-order Traversal:\n");
    preorderTraversal(root);
    printf("\n");
    
    printf("Post-order Traversal:\n");
    postorderTraversal(root);
    printf("\n");
    
    // Search for a specific value in the BST.
    int searchValue = 40;
    Node* result = searchNode(root, searchValue);
    if (result != NULL) {
        printf("Node with value %d found in the BST.\n", searchValue);
    } else {
        printf("Node with value %d not found in the BST.\n", searchValue);
    }
    
    // Note: In a complete implementation, you should free all allocated memory
    // to prevent memory leaks. For brevity, the deallocation is not shown here.
    
    return 0;
}
