#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char items[3][MAX]; // Only need to store up to 3 items (First, Middle, Surname)
    int top;
} Stack;

void initialize(Stack *s) {
    s->top = -1;
}

int is_empty(Stack *s) {
    return s->top == -1;
}

int is_full(Stack *s) {
    return s->top == 2; // Only need to store up to 3 items
}

void push(Stack *s, char *item) {
    if (!is_full(s)) {
        s->top++;
        strcpy(s->items[s->top], item);
    }
    else{
        printf("Stack is full");
    }
}

char* pop(Stack *s) {
    if (!is_empty(s)) {
        return s->items[s->top--];
    }
    return NULL;
}

void rearrange_name(char *name, char *rearranged_name) {
    Stack stack;
    initialize(&stack);

    char *token = strtok(name, " ");
    while (token != NULL) {
        push(&stack, token);
        token = strtok(NULL, " ");
    }

    char *surname = pop(&stack);
    char *middle_name = pop(&stack);
    char *first_name = pop(&stack);

    sprintf(rearranged_name, "%s %s %s", surname, first_name, middle_name);
}

int main() {
    char name[MAX];
    char rearranged_name[MAX];

    printf("Enter the name (First Middle Surname): ");
    fgets(name, MAX, stdin);

    size_t len = strlen(name);
    if (len > 0 && name[len - 1] == '\n') {
        name[len - 1] = '\0';
    }

    rearrange_name(name, rearranged_name);

    printf("Rearranged Name: %s\n", rearranged_name);

    return 0;
}
