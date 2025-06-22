/*
 * Project 8: Array-Based Stack Implementation
 * Author: Bocaletto Luca
 * Date: 2025-06-22
 * GitHub: bocaletto-luca
 *
 * Description:
 * This program implements a simple stack data structure using an array.
 * It includes functions to push an element onto the stack, pop an element from
 * the stack, and peek at the top element without removing it.
 *
 * Key Concepts:
 * - Last In First Out (LIFO) data structure.
 * - Fixed-size array implementation with error checking for overflow and underflow.
 * - Modular design with dedicated functions for stack operations.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100  // Maximum capacity of the stack

// Stack structure definition
typedef struct {
    int items[MAX_STACK_SIZE]; // Array to store stack elements
    int top;                   // Index of the top element; -1 indicates an empty stack
} Stack;

/*
 * Function: initializeStack
 * ---------------------------
 * Sets the top index of the stack to -1 to indicate that it is empty.
 *
 * stack: Pointer to the stack structure.
 */
void initializeStack(Stack *stack) {
    stack->top = -1;
}

/*
 * Function: isFull
 * ----------------
 * Checks if the stack is full.
 *
 * stack: Pointer to the stack structure.
 *
 * returns: 1 if the stack is full; 0 otherwise.
 */
int isFull(Stack *stack) {
    return stack->top == MAX_STACK_SIZE - 1;
}

/*
 * Function: isEmpty
 * -----------------
 * Checks if the stack is empty.
 *
 * stack: Pointer to the stack structure.
 *
 * returns: 1 if the stack is empty; 0 otherwise.
 */
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

/*
 * Function: push
 * --------------
 * Pushes an integer onto the stack.
 *
 * stack: Pointer to the stack structure.
 * item: The integer to be pushed onto the stack.
 *
 * returns: 0 on success, or -1 if the stack is full (overflow condition).
 */
int push(Stack *stack, int item) {
    if (isFull(stack)) {
        // Cannot push element; the stack is full.
        return -1;
    }
    // Increment the top index and insert the new element.
    stack->items[++(stack->top)] = item;
    return 0;
}

/*
 * Function: pop
 * -------------
 * Removes the top element from the stack and returns it.
 *
 * stack: Pointer to the stack structure.
 * item: Pointer to an integer where the popped element will be stored.
 *
 * returns: 0 on success, or -1 if the stack is empty (underflow condition).
 */
int pop(Stack *stack, int *item) {
    if (isEmpty(stack)) {
        // Cannot pop element; the stack is empty.
        return -1;
    }
    // Retrieve the top element, then decrement the top index.
    *item = stack->items[(stack->top)--];
    return 0;
}

/*
 * Function: peek
 * --------------
 * Retrieves the top element of the stack without removing it.
 *
 * stack: Pointer to the stack structure.
 * item: Pointer to an integer where the top element will be stored.
 *
 * returns: 0 on success, or -1 if the stack is empty.
 */
int peek(Stack *stack, int *item) {
    if (isEmpty(stack)) {
        // No elements to peek; the stack is empty.
        return -1;
    }
    // Retrieve the element at the top of the stack.
    *item = stack->items[stack->top];
    return 0;
}

/*
 * Function: main
 * --------------
 * Demonstrates the usage of the array-based stack by pushing, peeking,
 * and popping elements.
 */
int main(void) {
    Stack stack;         // Declare a stack instance.
    int poppedItem;      // Variable for storing popped item.

    // Initialize the stack.
    initializeStack(&stack);

    // Demonstrate push operations.
    printf("Pushing values onto the stack:\n");
    for (int i = 1; i <= 3; ++i) {
        int value = i * 10;
        if (push(&stack, value) == 0) {
            printf("Pushed %d onto the stack.\n", value);
        } else {
            printf("Error: Stack overflow when pushing %d.\n", value);
        }
    }

    // Peek at the top item of the stack.
    int topItem;
    if (peek(&stack, &topItem) == 0) {
        printf("Current top item is: %d\n", topItem);
    } else {
        printf("Error: Stack is empty, nothing to peek.\n");
    }

    // Demonstrate pop operations until the stack is empty.
    printf("Popping values from the stack:\n");
    while (!isEmpty(&stack)) {
        if (pop(&stack, &poppedItem) == 0) {
            printf("Popped %d from the stack.\n", poppedItem);
        } else {
            printf("Error: Stack underflow, cannot pop.\n");
        }
    }

    // End the program successfully.
    return 0;
}
