#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert()
{
    struct node *newnode, *temp;
    int x;

    printf("Enter value: ");
    scanf("%d", &x);

    newnode = malloc(sizeof(struct node));

    if(newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    newnode->data = x;
    newnode->next = NULL;

    if(head == NULL)
        head = newnode;
    else
    {
        temp = head;

        while(temp->next != NULL)
            temp = temp->next;

        temp->next = newnode;
    }
}

void delete()
{
    struct node *temp = head, *prev = NULL;
    int x;

    printf("Enter value to delete: ");
    scanf("%d", &x);

    while(temp != NULL && temp->data != x)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL)
        printf("Value not found\n");
    else
    {
        if(prev == NULL)
            head = temp->next;
        else
            prev->next = temp->next;

        free(temp);
        printf("Deleted successfully\n");
    }
}

void search()
{
    struct node *temp = head;
    int x, pos = 1;

    printf("Enter value to search: ");
    scanf("%d", &x);

    while(temp != NULL)
    {
        if(temp->data == x)
        {
            printf("Found at position %d\n", pos);
            return;
        }

        temp = temp->next;
        pos++;
    }

    printf("Value not found\n");
}

void display()
{
    struct node *temp = head;

    if(head == NULL)
        printf("List is empty\n");

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{
    int ch;

    while(1)
    {
        printf("\n1.Insert 2.Delete 3.Search 4.Display 5.Exit\n");
        scanf("%d", &ch);

        if(ch == 1)
            insert();
        else if(ch == 2)
            delete();
        else if(ch == 3)
            search();
        else if(ch == 4)
            display();
        else if(ch == 5)
            break;
    }

    while(head != NULL)
    {
        struct node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
