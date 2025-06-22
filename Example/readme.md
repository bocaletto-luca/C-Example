# 20 Project Example in C Language
#### Author: Bocaletto Luca

---

1. **Hello World Program**  
   - **Description:** Introduces the basic structure of a C program. The code prints "Hello, World!" to the console.  
   - **Key Concepts:**  
     - `main()` function  
     - `printf()` for output  
     - Compilation basics  
   - **Example Focus:** Demonstrate the simplest program with complete inline comments that explain each line.

2. **Simple Calculator**  
   - **Description:** A command-line calculator that performs basic arithmetic operations (addition, subtraction, multiplication, division) based on user input.  
   - **Key Concepts:**  
     - User input using `scanf()`  
     - Conditional statements (`if`/`else`)  
     - Function creation and modularity  
   - **Example Focus:** Include error checking for division by zero and clear, descriptive comments about operator precedence.

3. **Temperature Converter**  
   - **Description:** Converts temperature values from Celsius to Fahrenheit (or vice versa) based on user selection.  
   - **Key Concepts:**  
     - Input/output operations  
     - Mathematical formula implementation  
     - Creating helper functions for conversion  
   - **Example Focus:** Detail each mathematical step with comments, ensuring clarity on how numbers are converted.

4. **Random Number Guessing Game**  
   - **Description:** The computer randomly picks a number, and the user is invited to guess the number, receiving hints (too high/low) after each attempt.  
   - **Key Concepts:**  
     - Random number generation via `rand()` and seeding with `srand()`  
     - Loop constructs (`while` or `do-while`)  
     - Conditional logic for hinting  
   - **Example Focus:** Use comments to explain the use of randomness and how loops can be used to control game flow.

5. **Fibonacci Sequence Generator**  
   - **Description:** Generates and prints out the Fibonacci sequence up to a user-specified number of terms.  
   - **Key Concepts:**  
     - Iterative loops (with a potential recursive variant)  
     - Array usage (for storage, if desired)  
     - Function decomposition for clarity  
   - **Example Focus:** Comment on the logic behind recursion vs. iteration in generating sequence numbers.

6. **Prime Number Checker**  
   - **Description:** Determines whether the input number is prime by checking for factors.  
   - **Key Concepts:**  
     - Looping through potential divisors  
     - Conditional statements and efficiency improvements (e.g., loop until √n)  
   - **Example Focus:** Explain in detail how to optimize the divisor checking with inline mathematical notes.

7. **File I/O: Read and Write**  
   - **Description:** A program that demonstrates basic file operations by writing user input to a file and then reading it back.  
   - **Key Concepts:**  
     - File handling with `fopen()`, `fprintf()`, `fscanf()`, and `fclose()`  
     - Error checking for file operations  
   - **Example Focus:** Provide detailed commentary on best practices with file pointers and resource management.

8. **Array-Based Stack Implementation**  
   - **Description:** Implements a simple stack data structure with functions for `push`, `pop`, and `peek` using arrays.  
   - **Key Concepts:**  
     - Data structures (modeling a stack)  
     - Array manipulation and boundary checking  
     - Modular function design  
   - **Example Focus:** Comment every function to explain why and how the stack is manipulated, including considerations for overflow/underflow.

9. **Sorting Algorithms: Bubble Sort and Insertion Sort**  
   - **Description:** Implements two classic sorting techniques to sort an array of integers.  
   - **Key Concepts:**  
     - Nested loops and algorithm design  
     - Efficiency considerations  
     - Comparison of two sorting methods  
   - **Example Focus:** Inline comments should outline the logic behind each pass of the algorithm and explain why one might choose one sort over another.

10. **Searching Algorithms: Linear and Binary Search**  
    - **Description:** Provides implementations for both linear search and binary search to locate elements in an array.  
    - **Key Concepts:**  
      - Looping and condition checking  
      - Recursive implementation (for binary search)  
      - Efficiency and preconditions (e.g., sorted arrays for binary search)  
    - **Example Focus:** Comments should compare the two methods, noting their use cases and the importance of data ordering.

11. **Singly Linked List Implementation**  
    - **Description:** Creates a singly linked list and implements functions to insert, delete, and search nodes.  
    - **Key Concepts:**  
      - Dynamic memory allocation using `malloc()` and `free()`  
      - Structs in C  
      - Pointer manipulation for list traversal  
    - **Example Focus:** Each operation (insertion, deletion, search) is clearly explained, including comments on pointer usage and memory management.

12. **Basic Banking System Simulation**  
    - **Description:** Simulates a simple banking system where users can create accounts, deposit, withdraw, and check balances.  
    - **Key Concepts:**  
      - Structs to represent accounts  
      - File I/O for persistent storage  
      - Menu-driven interfaces and error handling  
    - **Example Focus:** Detailed comments on struct fields, how data is stored, and the logic behind each transaction.

13. **Tic Tac Toe Game**  
    - **Description:** Develop a text-based Tic Tac Toe game with logic to check for win conditions and handle player turns interactively.  
    - **Key Concepts:**  
      - 2D arrays for game boards  
      - Game logic and condition checking  
      - User input processing  
    - **Example Focus:** Inline commentary should describe how the board is updated and the conditions under which a player wins or the game ends in a tie.

14. **Hangman Game**  
    - **Description:** Implements the classic Hangman game where the user guesses letters to reveal a hidden word.  
    - **Key Concepts:**  
      - String manipulation and arrays  
      - Looping for repeated guesses  
      - Conditional logic for correct/incorrect guesses  
    - **Example Focus:** Comments will help clarify how the word is masked and progressively revealed, along with error handling for repeated guesses.

15. **Caesar Cipher for Encryption/Decryption**  
    - **Description:** Encrypts and decrypts text using the Caesar cipher method by shifting text characters.  
    - **Key Concepts:**  
      - ASCII arithmetic and modular arithmetic  
      - String handling and user input  
      - Simple encryption techniques  
    - **Example Focus:** Each step of shifting letters will be thoroughly explained through comments, making the code self-explanatory.

16. **Student Record Management System**  
    - **Description:** A system that allows the management of student records—including creation, updating, searching, and deletion—all stored in a file.  
    - **Key Concepts:**  
      - Use of structs for student data  
      - File I/O for persistent record storage  
      - Dynamic data handling and menu-driven design  
    - **Example Focus:** Extensive commentary to explain file formats used, data structures for holding records, and the logic behind CRUD (Create, Read, Update, Delete) operations.

17. **Memory Management and Pointer Exercises**  
    - **Description:** A collection of exercises focusing on pointer arithmetic, dynamic memory allocation, and safe memory deallocation.  
    - **Key Concepts:**  
      - Deep dive into pointers and memory addresses  
      - Using `malloc()`, `calloc()`, and `free()`  
      - Debugging common memory issues (e.g., segmentation faults)  
    - **Example Focus:** Each exercise includes step-by-step comments tracing pointer behavior and memory allocation details.

18. **Multithreading with POSIX Threads (pthreads)**  
    - **Description:** A simple multithreaded program that spawns multiple threads to run a function concurrently, illustrating basic thread management.  
    - **Key Concepts:**  
      - POSIX thread creation with `pthread_create()`  
      - Thread synchronization (e.g., using mutexes)  
      - Addressing potential race conditions  
    - **Example Focus:** Comments will explain the threading model, how to join threads, and strategies for safe concurrent execution.

19. **Basic Chatbot Program**  
    - **Description:** Develop a text-based interactive chatbot that replies to user input using simple pattern matching and predetermined responses.  
    - **Key Concepts:**  
      - String parsing and handling  
      - Conditional logic to match user phrases  
      - Loop constructs for sustained interaction  
    - **Example Focus:** Thorough comments that detail how input is processed, how matches are found, and how the conversation flow is maintained.

20. **Binary Search Tree (BST) Implementation**  
    - **Description:** Implements a binary search tree featuring functions to insert nodes, perform searches, and traverse the tree using in-order, pre-order, and post-order methods.  
    - **Key Concepts:**  
      - Dynamic memory allocation and pointer-based structures  
      - Recursive functions for tree operations  
      - Understanding and implementing tree traversals  
    - **Example Focus:** Comprehensive inline comments explain recursion, tree management, and the nuances of pointer operations in the tree structure.

---
