#include <stdio.h>
#define SIZE 5

int q[SIZE], front = -1, rear = -1;

int full()
{
    return (front == 0 && rear == SIZE-1) ||
           (front == rear + 1);
}

int empty()
{
    return front == -1;
}

void insertFront(int x)
{
    if(full())
        printf("Deque is full\n");
    else
    {
        if(empty())
            front = rear = 0;
        else if(front == 0)
            front = SIZE-1;
        else
            front--;

        q[front] = x;
    }
}

void insertRear(int x)
{
    if(full())
        printf("Deque is full\n");
    else
    {
        if(empty())
            front = rear = 0;
        else
            rear = (rear + 1) % SIZE;

        q[rear] = x;
    }
}

void deleteFront()
{
    if(empty())
        printf("Deque is empty\n");
    else
    {
        printf("Deleted: %d\n", q[front]);

        if(front == rear)
            front = rear = -1;
        else
            front = (front + 1) % SIZE;
    }
}

void deleteRear()
{
    if(empty())
        printf("Deque is empty\n");
    else
    {
        printf("Deleted: %d\n", q[rear]);

        if(front == rear)
            front = rear = -1;
        else if(rear == 0)
            rear = SIZE-1;
        else
            rear--;
    }
}

void display()
{
    int i;

    if(empty())
        printf("Deque is empty\n");
    else
    {
        i = front;

        while(1)
        {
            printf("%d ", q[i]);
            if(i == rear)
                break;
            i = (i + 1) % SIZE;
        }
        printf("\n");
    }
}

int main()
{
    int ch, x;

    while(1)
    {
        printf("\n1.Insert Front 2.Insert Rear");
        printf("\n3.Delete Front 4.Delete Rear");
        printf("\n5.Display 6.Exit\n");
        scanf("%d", &ch);

        if(ch == 1 || ch == 2)
        {
            printf("Enter value: ");
            scanf("%d", &x);

            if(ch == 1)
                insertFront(x);
            else
                insertRear(x);
        }
        else if(ch == 3)
            deleteFront();
        else if(ch == 4)
            deleteRear();
        else if(ch == 5)
            display();
        else if(ch == 6)
            break;
    }

    return 0;
}
