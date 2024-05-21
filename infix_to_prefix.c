#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Stack structure definition
struct Stack {
    int top;
    unsigned capacity;
    char* array;
};

// Function to create a stack of given capacity
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an item to stack
void push(struct Stack* stack, char item) {
    stack->array[++stack->top] = item;
}

// Function to pop an item from stack
char pop(struct Stack* stack) {
    if (isEmpty(stack))
        return '\0';
    return stack->array[stack->top--];
}

// Function to get top item from stack
char peek(struct Stack* stack) {
    if (isEmpty(stack))
        return '\0';
    return stack->array[stack->top];
}

// Function to check if the character is an operator
int isOperator(char c) {
    return (!isalpha(c) && !isdigit(c));
}

// Function to get the priority of operators
int getPriority(char C) {
    if (C == '-' || C == '+')
        return 1;
    else if (C == '*' || C == '/')
        return 2;
    else if (C == '^')
        return 3;
    return 0;
}

// Function to convert the infix expression to postfix
char* infixToPostfix(char* infix) {
    int l = strlen(infix);
    struct Stack* stack = createStack(l + 1);
    char* output = (char*)malloc((l + 1) * sizeof(char));
    int k = 0;

    for (int i = 0; i < l; i++) {
        if (isalpha(infix[i]) || isdigit(infix[i])) {
            output[k++] = infix[i];
        }
        else if (infix[i] == '(') {
            push(stack, '(');
        }
        else if (infix[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                output[k++] = pop(stack);
            }
            pop(stack);
        }
        else {
            if (isOperator(peek(stack))) {
                if (infix[i] == '^') {
                    while (getPriority(infix[i]) <= getPriority(peek(stack))) {
                        output[k++] = pop(stack);
                    }
                }
                else {
                    while (getPriority(infix[i]) < getPriority(peek(stack))) {
                        output[k++] = pop(stack);
                    }
                }
                push(stack, infix[i]);
            }
        }
    }
    while (!isEmpty(stack)) {
        output[k++] = pop(stack);
    }
    output[k] = '\0';
    return output;
}

// Function to reverse a string
void reverse(char* str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

// Function to convert infix to prefix notation
char* infixToPrefix(char* infix) {
    int l = strlen(infix);
    reverse(infix);
    for (int i = 0; i < l; i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        }
        else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }

    char* prefix = infixToPostfix(infix);
    reverse(prefix);
    return prefix;
}

int main() {
    char infix[] = "x+y*z/w+u";
    char* prefix = infixToPrefix(infix);
    printf("%s\n", prefix);
    free(prefix);
    return 0;
}