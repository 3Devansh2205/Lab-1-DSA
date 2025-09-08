#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;


void push(char ch) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = ch;
    }
}


char pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
        return '\0';
    } else {
        return stack[top--];
    }
}


void reverseString(char str[]) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        push(str[i]);
    }

    for (i = 0; str[i] != '\0'; i++) {
        str[i] = pop();
    }
}

int main() {
    char str[MAX];

    printf("Enter a string: ");
    fgets(str, MAX, stdin);


    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    reverseString(str);
    printf("Reversed string: %s\n", str);

    return 0;
}
