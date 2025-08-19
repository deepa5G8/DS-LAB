#include <stdio.h>
#include <stdlib.h>

// Define a structure for the stack node
struct Node {
    int data;              // Data stored in the node
    struct Node* next;     // Pointer to the next node
};

// Function to push an element onto the stack
void push(struct Node** top, int value) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Stack overflow! Unable to allocate memory.\n");
        return;
    }
    newNode->data = value;      // Assign the value to the new node
    newNode->next = *top;       // Link the new node to the current top
    *top = newNode;             // Update the top pointer
    printf("Pushed %d onto the stack.\n", value);
}

// Function to pop an element from the stack
int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack underflow! The stack is empty.\n");
        return -1; // Return -1 to indicate an error
    }
    struct Node* temp = *top;   // Temporary pointer to the top node
    int poppedValue = temp->data; // Store the data to return
    *top = (*top)->next;        // Update the top pointer
    free(temp);                 // Free the memory of the popped node
    printf("Popped %d from the stack.\n", poppedValue);
    return poppedValue;
}

// Function to display the stack
void display(struct Node* top) {
    if (top == NULL) {
        printf("The stack is empty.\n");
        return;
    }
    printf("Stack elements are: ");
    struct Node* temp = top;
    while (temp != NULL) {
        printf("%d ", temp->data); // Print the data of each node
        temp = temp->next;        // Move to the next node
    }
    printf("\n");
}

// Main function
int main() {
    struct Node* stack = NULL; // Initialize the stack as empty

    int choice, value;
    while (1) {
        // Display menu
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                pop(&stack);
                break;
            case 3:
                display(stack);
                break;
            case 4:
                printf("Exiting program.\n");
                // Free remaining nodes before exiting
                while (stack != NULL) {
                    pop(&stack);
                }
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}


