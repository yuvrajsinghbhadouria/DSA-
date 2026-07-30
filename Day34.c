/*Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result

Example:
Input:
2 3 1 * + 9 -

Output:
-4

Explanation:
Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Node structure for stack
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Push operation
void push(Node** top, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}

// Pop operation
int pop(Node** top) {
    if (*top == NULL) {
        printf("Stack Underflow\n");
        exit(1);
    }
    Node* temp = *top;
    int value = temp->data;
    *top = temp->next;
    free(temp);
    return value;
}

// Evaluate postfix expression
int evaluatePostfix(char* expr) {
    Node* stack = NULL;
    char* token = strtok(expr, " ");

    while (token != NULL) {

        // If operand
        if (isdigit(token[0]) || 
           (token[0] == '-' && isdigit(token[1]))) {
            push(&stack, atoi(token));
        }
        // If operator
        else {
            int b = pop(&stack);
            int a = pop(&stack);
            int result;

            switch (token[0]) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
                default:
                    printf("Invalid operator\n");
                    exit(1);
            }

            push(&stack, result);
        }

        token = strtok(NULL, " ");
    }

    return pop(&stack);
}

int main() {
    char expr[100];

    printf("Enter postfix expression:\n");
    fgets(expr, sizeof(expr), stdin);

    // Remove newline
    expr[strcspn(expr, "\n")] = '\0';

    int result = evaluatePostfix(expr);

    printf("%d\n", result);

    return 0;
}