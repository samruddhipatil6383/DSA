#include <stdio.h>
#define SIZE 5

int queue[SIZE], front = 0, rear = -1;

void addTask(int task)
{
    if(rear == SIZE-1)
        printf("Queue is full\n");
    else
    {
        queue[++rear] = task;
        printf("Task added\n");
    }
}

void processTask()
{
    if(front > rear)
        printf("No tasks pending\n");
    else
        printf("Processing task: %d\n", queue[front++]);
}

void display()
{
    int i;

    if(front > rear)
        printf("Queue is empty\n");
    else
    {
        for(i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int main()
{
    int ch, task;

    while(1)
    {
        printf("\n1.Add Task 2.Process Task 3.Display 4.Exit\n");
        scanf("%d", &ch);

        if(ch == 1)
        {
            printf("Enter task number: ");
            scanf("%d", &task);
            addTask(task);
        }
        else if(ch == 2)
            processTask();
        else if(ch == 3)
            display();
        else if(ch == 4)
            break;
    }

    return 0;
}
