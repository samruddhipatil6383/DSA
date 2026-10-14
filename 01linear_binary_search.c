
#include <stdio.h>
int main() {
    int a[100], n, key, i, count;
    int low, high, mid, found;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements in sorted order:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    // Linear Search
    count = 0;
    found = 0;

    for (i = 0; i < n; i++) {
        count++;

        if (a[i] == key) {
            found = 1;
            break;
        }
    }

    printf("\nLinear Search:\n");
    if (found)
        printf("Element found at position %d\n", i + 1);
    else
        printf("Element not found\n");

    printf("Comparisons: %d\n", count);

    // Binary Search
    low = 0;
    high = n - 1;
    count = 0;
    found = 0;

    while (low <= high) {
        mid = (low + high) / 2;
        count++;

        if (a[mid] == key) {
            found = 1;
            break;
        }
        else if (a[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    printf("\nBinary Search:\n");
    if (found)
        printf("Element found at position %d\n", mid + 1);
    else
        printf("Element not found\n");

    printf("Comparisons: %d\n", count);

    return 0;
}
