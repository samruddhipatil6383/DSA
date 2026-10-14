#include <stdio.h>
#include <time.h>

int fib(int n)
{
    if(n <= 1)
        return n;

    return fib(n-1) + fib(n-2);
}

int main()
{
    int n, i, a = 0, b = 1, c;
    clock_t start, end;
    double t1, t2;

    printf("Enter number of terms (1-40): ");
    scanf("%d", &n);

    if(n < 1 || n > 40)
    {
        printf("Enter a value between 1 and 40\n");
        return 0;
    }

    start = clock();
    printf("Recursive: ");
    for(i = 0; i < n; i++)
        printf("%d ", fib(i));
    end = clock();
    t1 = (double)(end-start)/CLOCKS_PER_SEC;

    start = clock();
    printf("\nIterative: ");
    a = 0;
    b = 1;

    for(i = 0; i < n; i++)
    {
        printf("%d ", a);
        c = a + b;
        a = b;
        b = c;
    }
    end = clock();
    t2 = (double)(end-start)/CLOCKS_PER_SEC;

    printf("\nRecursive time: %f seconds", t1);
    printf("\nIterative time: %f seconds\n", t2);

    return 0;
}
