#include <stdio.h>

int a[100], n = 0;

void heapify(int i)
{
    int largest = i;
    int l = 2*i + 1, r = 2*i + 2, temp;

    if(l < n && a[l] > a[largest])
        largest = l;
    if(r < n && a[r] > a[largest])
        largest = r;

    if(largest != i)
    {
        temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        heapify(largest);
    }
}

void insert(int x)
{
    int i = n, temp;
    a[n++] = x;

    while(i > 0 && a[(i-1)/2] < a[i])
    {
        temp = a[i];
        a[i] = a[(i-1)/2];
        a[(i-1)/2] = temp;
        i = (i-1)/2;
    }
}

void deleteRoot()
{
    if(n == 0)
    {
        printf("Heap is empty\n");
        return;
    }

    printf("Deleted element: %d\n", a[0]);
    a[0] = a[n-1];
    n--;
    heapify(0);
}

void display()
{
    for(int i=0; i<n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main()
{
    int ch, x;

    while(1)
    {
        printf("\n1.Insert 2.Delete 3.Display 4.Heap Sort 5.Exit\n");
        scanf("%d", &ch);

        if(ch == 1)
        {
            printf("Enter value: ");
            scanf("%d", &x);
            if(n < 100)
                insert(x);
            else
                printf("Heap is full\n");
        }
        else if(ch == 2)
            deleteRoot();
        else if(ch == 3)
            display();
        else if(ch == 4)
        {
            while(n > 0)
                deleteRoot();
        }
        else if(ch == 5)
            break;
    }

    return 0;
}
