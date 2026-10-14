
#include <stdio.h>
#include <time.h>

void bubbleSort(int a[], int n, int *comp) {
    int i, j, temp;

    for (i = 0; i < n - 1; i++) {
     for (j = 0; j < n - i - 1; j++) {
            (*comp)++;

if (a[j] > a[j + 1]) {
 temp = a[j];
a[j] = a[j + 1];
 a[j + 1] = temp; }
}
}
}

void selectionSort(int a[], int n, int *comp) {
    int i, j, min, temp;

for (i = 0; i < n - 1; i++) {
        min = i;

for (j = i + 1; j < n; j++) {
            (*comp)++;
        
 if (a[j] < a[min])
  min = j;
        }

        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
}
}

void insertionSort(int a[], int n, int *comp) {
    int i, j, key;

    for (i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;

        while (j >= 0) {
            (*comp)++;

            if (a[j] > key) {
                a[j + 1] = a[j];
                j--;
} else {
 break;
 }
 }

  a[j + 1] = key;
    }
}

int main() {
    int n, i, choice;
    int a[1000], b[1000], s[1000], in[1000];
    int c1 = 0, c2 = 0, c3 = 0;
    clock_t start, end;
    double t1, t2, t3;

    printf("Enter number of elements (max 1000): ");
    scanf("%d", &n);

    if (n < 1 || n > 1000) {
        printf("Invalid input size.\n");
        return 0;
    }

    printf("Enter array elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        b[i] = s[i] = in[i] = a[i];
    }

    start = clock();
    bubbleSort(b, n, &c1);
    end = clock();
    t1 = (double)(end - start) / CLOCKS_PER_SEC;

    start = clock();
    selectionSort(s, n, &c2);
    end = clock();
    t2 = (double)(end - start) / CLOCKS_PER_SEC;

    start = clock();
    insertionSort(in, n, &c3);
    end = clock();
    t3 = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nAlgorithm       Comparisons    Time (seconds)\n");
    printf("Bubble Sort     %d             %.6f\n", c1, t1);
    printf("Selection Sort  %d             %.6f\n", c2, t2);
    printf("Insertion Sort  %d             %.6f\n", c3, t3);

    return 0;
}
