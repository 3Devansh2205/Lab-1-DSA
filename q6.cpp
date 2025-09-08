#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    char data;
    struct Node* next;
} Node;


void push(Node** top, char ch) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = ch;
    newNode->next = *top;
    *top = newNode;
}


char pop(Node** top)
    if (*top == NULL) return '\0';
    Node* temp = *top;
    char popped = temp->data;
    *top = temp->next;
    free(temp);
    return popped;
}
int isEmpty(Node* top) {
    return top == NULL;
}

int isBalanced(char* expr) {
    Node* stack = NULL;
    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            push(&stack, ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty(stack)) return 0;
            char topChar = pop(&stack);
            if ((ch == ')' && topChar != '(') ||
                (ch == '}' && topChar != '{') ||
                (ch == ']' && topChar != '[')) {
                return 0;
            }
        }
    }
    return isEmpty(stack);
}

int main() {
    char expression[100];
    printf("Enter an expression: ");
    scanf("%s", expression);

    if (isBalanced(expression))
        printf("Balanced parentheses\n");
    else
        printf("Unbalanced parentheses\n");

    return 0;
}
