#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int x)
{
    struct node *newnode;
    newnode = malloc(sizeof(struct node));

    if(newnode == NULL)
    {
        printf("Memory full\n");
        return;
    }

    newnode->data = x;
    newnode->next = top;
    top = newnode;
}

void pop()
{
    struct node *temp;

    if(top == NULL)
        printf("Stack is empty\n");
    else
    {
        temp = top;
        printf("Removed: %d\n", top->data);
        top = top->next;
        free(temp);
    }
}

void display()
{
    struct node *temp = top;

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
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

    while(top != NULL)
        pop();

    return 0;
}
