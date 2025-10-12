#include <stdio.h>
#define MAX 100

char stack[MAX];
int top = -1;

// Push character onto stack
void push(char c) {
    stack[++top] = c;
}

// Pop character from stack
char pop() {
    if (top == -1)
        return '\0'; // Empty stack
    return stack[top--];
}

int main() {
    char expr[MAX];
    int balanced = 1; // Assume balanced

    printf("Enter expression: ");
    fgets(expr, MAX, stdin);

    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];

        // Push opening brackets
        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        }
        // Handle closing brackets
        else if (ch == ')' || ch == '}' || ch == ']') {
            char open = pop();

            if ((ch == ')' && open != '(') ||
                (ch == '}' && open != '{') ||
                (ch == ']' && open != '[')) {
                balanced = 0;
                break;
            }
        }
    }

    if (top != -1) balanced = 0; // Stack not empty → not balanced

    if (balanced)
        printf("Balanced\n");
    else
        printf("Not Balanced\n");

    return 0;
}
