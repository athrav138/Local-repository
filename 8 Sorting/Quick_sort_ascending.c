#include <stdio.h>

int main() {
    int arr[100], n, i, j, pivot, temp, low, high;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for(i = 0; i < n; i++) {
        printf("Enter %d element: ", i);
        scanf("%d", &arr[i]);
    }

    int stack[100], top = -1;
    stack[++top] = 0;
    stack[++top] = n - 1;

    while (top >= 0) {
        high = stack[top--];
        low = stack[top--];

        pivot = arr[high];
        int pIndex = low;

        for(i = low; i < high; i++) {
            if(arr[i] < pivot) {
                temp = arr[i];
                arr[i] = arr[pIndex];
                arr[pIndex] = temp;
                pIndex++;
            }
        }

        temp = arr[pIndex];
        arr[pIndex] = arr[high];
        arr[high] = temp;

        if(pIndex - 1 > low) {
            stack[++top] = low;
            stack[++top] = pIndex - 1;
        }

        if(pIndex + 1 < high) {
            stack[++top] = pIndex + 1;
            stack[++top] = high;
        }
    }

    printf("Array after quick sort:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

return 0;
}
