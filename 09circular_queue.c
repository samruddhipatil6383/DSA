#include <stdio.h>
#define SIZE 5

int q[SIZE], front = -1, rear = -1;

void insert(int x)
{
    if((rear + 1) % SIZE == front)
        printf("Queue is full\n");
    else
    {
        if(front == -1)
            front = 0;

        rear = (rear + 1) % SIZE;
        q[rear] = x;
        printf("Inserted: %d\n", x);
    }
}

void delete()
{
    if(front == -1)
        printf("Queue is empty\n");
    else
    {
        printf("Deleted: %d\n", q[front]);

        if(front == rear)
            front = rear = -1;
        else
            front = (front + 1) % SIZE;
    }
}

void display()
{
    int i;

    if(front == -1)
        printf("Queue is empty\n");
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
        printf("\n1.Insert 2.Delete 3.Display 4.Exit\n");
        scanf("%d", &ch);

        if(ch == 1)
        {
            printf("Enter value: ");
            scanf("%d", &x);
            insert(x);
        }
        else if(ch == 2)
            delete();
        else if(ch == 3)
            display();
        else if(ch == 4)
            break;
    }

    return 0;
}
