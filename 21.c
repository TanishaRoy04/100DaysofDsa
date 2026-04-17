#include <stdio.h>
#define MAX 5

int stack[MAX], top=-1;

void push(int val) {
    if(top==MAX-1) return;
    stack[++top]=val;
}

int pop() {
    if(top==-1) return -1;
    return stack[top--];
}

int main() {
    push(10);
    push(20);
    printf("%d",pop());
}