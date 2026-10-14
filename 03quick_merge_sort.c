#include <stdio.h>
#include <time.h>

void quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int pivot = a[high];
        int i = low - 1, j, temp;

        for (j = low; j < high; j++)
        {
            if (a[j] < pivot)
            {
                i++;
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }

        temp = a[i + 1];
        a[i + 1] = a[high];
        a[high] = temp;

        int p = i + 1;
        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

void merge(int a[], int low, int mid, int high)
{
    int b[1000], i = low, j = mid + 1, k = low;

    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }

    while (i <= mid)
        b[k++] = a[i++];

    while (j <= high)
        b[k++] = a[j++];

    for (i = low; i <= high; i++)
        a[i] = b[i];
}

void mergeSort(int a[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

int main()
{
    int a[1000], b[1000], n, i;
    clock_t start, end;
    double t1, t2;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n < 1 || n > 1000)
    {
        printf("Invalid size");
        return 0;
    }

    printf("Enter array elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }

    start = clock();
    quickSort(a, 0, n - 1);
    end = clock();
    t1 = (double)(end - start) / CLOCKS_PER_SEC;

    start = clock();
    mergeSort(b, 0, n - 1);
    end = clock();
    t2 = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nQuick Sort: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\nTime: %.6f seconds", t1);

    printf("\n\nMerge Sort: ");
    for (i = 0; i < n; i++)
        printf("%d ", b[i]);
    printf("\nTime: %.6f seconds\n", t2);

    return 0;
}
