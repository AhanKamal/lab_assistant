/*4. Develop a program in C for simulating a Printer Queue using Queue data structure with the following 
operations: 
a. Add a print job to the Printer Queue. 
b. Process a print job from the Printer Queue (delete). 
c. Display the number of print jobs currently waiting in the Queue. 
d. Demonstrate Queue overflow and underflow conditions. 
e. Exit. */



#include <stdio.h>
#define MAX 5

int queue[MAX], front = 0, rear = 0, count = 0;

void addJob(int id)
{
    if (count == MAX)
        printf("Queue Overflow!\n");
    else {
        queue[rear] = id;
        rear = (rear + 1) % MAX;
        count++;
        printf("Added job: %d\n", id);
    }
}

void processJob(void)
{
    if (count == 0)
        printf("Queue Underflow!\n");
    else {
        printf("Processed job: %d\n", queue[front]);
        front = (front + 1) % MAX;
        count--;
    }
}

void display(void)
{
    printf("Print jobs waiting: %d\n", count);
}

int main(void)
{
    int choice, id;
    for (;;) {
        printf("\n1.Add job  2.Process job  3.Waiting count  4.Exit\nChoice: ");
        if (scanf("%d", &choice) != 1)
            return 1;
        switch (choice) {
            case 1:
                printf("Enter job ID: ");
                if (scanf("%d", &id) != 1)
                    return 1;
                addJob(id);
                break;
            case 2: processJob(); break;
            case 3: display(); break;
            case 4: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}

/*
TEST CASES AND EXPECTED OUTPUTS
Start each test with a fresh run. Enter inputs in the given order.
Menu: 1.Add job  2.Process job  3.Waiting count  4.Exit
Choice 1 is followed by a job ID. Menus and prompts are omitted
from the outputs below. Choice 4 exits without a message.
MAX is 5 so that overflow is easy to demonstrate; it can be changed.
Use job IDs 1..32767 for examples on both Turbo C and GCC.
This compact program accepts integer IDs (duplicates are allowed).
Non-numeric input exits with code 1 without an error message.
A circular queue reuses freed positions and processes jobs FIFO.
All three operations take O(1) time. Storage is O(MAX).

TEST 1: EMPTY QUEUE AND UNDERFLOW
Input sequence:
3 2 4
Expected output:
Print jobs waiting: 0
Queue Underflow!

TEST 2: ADD, PROCESS AND FIFO ORDER
Input sequence:
1 101 1 102 1 103 3 2 3 2 2 3 4
Expected output:
Added job: 101
Added job: 102
Added job: 103
Print jobs waiting: 3
Processed job: 101
Print jobs waiting: 2
Processed job: 102
Processed job: 103
Print jobs waiting: 0

TEST 3: OVERFLOW, CIRCULAR REUSE AND UNDERFLOW
Input sequence:
1 1 1 2 1 3 1 4 1 5 3 1 6 3 2 1 6 3 2 2 2 2 2 3 2 4
Expected output:
Added job: 1
Added job: 2
Added job: 3
Added job: 4
Added job: 5
Print jobs waiting: 5
Queue Overflow!
Print jobs waiting: 5
Processed job: 1
Added job: 6
Print jobs waiting: 5
Processed job: 2
Processed job: 3
Processed job: 4
Processed job: 5
Processed job: 6
Print jobs waiting: 0
Queue Underflow!

TEST 4: INVALID CHOICE AND EXIT
Input sequence:
9 3 4
Expected output:
Invalid choice!
Print jobs waiting: 0

*/
