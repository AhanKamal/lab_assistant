/* Program 3: 3. Develop a menu driven Program in C for the following operations on STACK of Integers (Array 
Implementation of Stack with maximum size MAX >15). 
a. Push an Element on to Stack. 
b. Pop an Element from Stack. 
c. Demonstrate Overflow and Underflow situations on Stack. 
d. Display the status of Stack at any given point of time. 
e. Exit. 
        Support structured program with appropriate functions for each of the above operations.  */

#include <stdio.h>
#define MAX 20

int stack[MAX], top = -1;

void push(int x)
{
    if (top == MAX - 1)
        printf("Stack Overflow!\n");
    else {
        stack[++top] = x;
        printf("Pushed: %d\n", x);
    }
}

void pop(void)
{
    if (top == -1)
        printf("Stack Underflow!\n");
    else
        printf("Popped: %d\n", stack[top--]);
}

void display(void)
{
    int i;
    if (top == -1)
        printf("Stack is empty.\n");
    else {
        printf("Stack (top to bottom), %d/%d elements:\n",
               top + 1, MAX);
        for (i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

int main(void)
{
    int choice, x;
    for (;;) {
        printf("\n1.Push  2.Pop  3.Display  4.Exit\nChoice: ");
        if (scanf("%d", &choice) != 1)
            return 1;
        switch (choice) {
            case 1:
                printf("Enter an integer: ");
                if (scanf("%d", &x) != 1)
                    return 1;
                push(x);
                break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}

/*
PROGRAM 3 - ARRAY IMPLEMENTATION OF AN INTEGER STACK
MAX = 20 (> 15). Push/pop: O(1). Display: O(n).
Start each test with a fresh run. Inputs are entered in order.
Choice 1 is followed by the integer to push.
Menu: 1.Push  2.Pop  3.Display  4.Exit
Outputs below omit repeated menus and input prompts.
Choice 4 exits without printing a message.
Use integer values within -32768..32767 for classic Turbo C.
Non-numeric input exits with return code 1 without a message.

TEST 1: EMPTY STACK AND UNDERFLOW
Input sequence:
3 2 4
Expected output:
Stack is empty.
Stack Underflow!

TEST 2: PUSH, DISPLAY AND LIFO
Input sequence:
1 10 1 20 1 30 3 2 3 2 2 2 3 4
Expected output:
Pushed: 10
Pushed: 20
Pushed: 30
Stack (top to bottom), 3/20 elements:
30 20 10
Popped: 30
Stack (top to bottom), 2/20 elements:
20 10
Popped: 20
Popped: 10
Stack Underflow!
Stack is empty.

TEST 3: OVERFLOW AND RECOVERY
Input sequence:
1 1 1 2 1 3 1 4 1 5 1 6 1 7 1 8 1 9 1 10 1 11 1 12 1 13 1 14 1 15 1 16 1 17
1 18 1 19 1 20 3 1 99 3 2 1 99 3 4
Expected output:
Pushed: 1
Pushed: 2
Pushed: 3
Pushed: 4
Pushed: 5
Pushed: 6
Pushed: 7
Pushed: 8
Pushed: 9
Pushed: 10
Pushed: 11
Pushed: 12
Pushed: 13
Pushed: 14
Pushed: 15
Pushed: 16
Pushed: 17
Pushed: 18
Pushed: 19
Pushed: 20
Stack (top to bottom), 20/20 elements:
20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1
Stack Overflow!
Stack (top to bottom), 20/20 elements:
20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1
Popped: 20
Pushed: 99
Stack (top to bottom), 20/20 elements:
99 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1

TEST 4: NEGATIVE INTEGERS AND ZERO
Input sequence:
1 -5 1 0 1 7 3 2 2 2 3 4
Expected output:
Pushed: -5
Pushed: 0
Pushed: 7
Stack (top to bottom), 3/20 elements:
7 0 -5
Popped: 7
Popped: 0
Popped: -5
Stack is empty.

TEST 5: INVALID MENU CHOICE
Input sequence:
9 3 4
Expected output:
Invalid choice!
Stack is empty.

*/
