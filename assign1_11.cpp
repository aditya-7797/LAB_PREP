#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int Stack[MAX];
int top = -1;

void push(int x) {
    if (top == MAX - 1) {
        printf("Stack is full\n");
    } else {
        Stack[++top] = x;
    }
}

int pop() {
    if (top == -1) {
        printf("Stack is empty\n");
        return -1;
    } else {
        return Stack[top--];
    }
}

int isPalindrome(char ch[]) {
    int length = strlen(ch);
    
    // Push all characters of the string into the stack
    for (int i = 0; i < length; i++) {
        push(ch[i]);
    }
    
    // Pop characters from the stack and compare
    for (int i = 0; i < length; i++) {
        if (ch[i] != pop()) {
            return 0;  // Not a palindrome
        }
    }
    return 1;  // Is a palindrome
}

int main() {
    printf("Enter the string:\n");

    char ch[20];
    scanf("%s", ch);

    if (isPalindrome(ch)) {
        printf("%s is a palindrome\n", ch);
    } else {
        printf("%s is not a palindrome\n", ch);
    }

    return 0;
}
