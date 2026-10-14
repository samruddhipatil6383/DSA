#include <stdio.h>
#define SIZE 5

int stack[SIZE], top = -1;

void push(int x)
{
    if(top == SIZE-1)
        printf("Stack is full\n");
    else
        stack[++top] = x;
}

void pop()
{
    if(top == -1)
        printf("Stack is empty\n");
    else
        printf("Removed: %d\n", stack[top--]);
}

void display()
{
    int i;
    for(i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

int main()
{
    int ch, x;

    while(1)
    {
        printf("\n1.Push 2.Pop 3.Display 4.Exit\n");
        scanf("%d", &ch);

        if(ch == 1)
        {
            printf("Enter value: ");
            scanf("%d", &x);
            push(x);
        }
        else if(ch == 2)
            pop();
        else if(ch == 3)
            display();
        else if(ch == 4)
            break;
    }

    return 0;
}
