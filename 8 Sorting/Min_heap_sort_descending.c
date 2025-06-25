#include <stdio.h>

void heapify(int arr[], int n, int i) {
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && arr[l] < arr[smallest])
        smallest = l;

    if (r < n && arr[r] < arr[smallest])
        smallest = r;

    if (smallest != i) {
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        heapify(arr, n, smallest);
    }
}

void buildMinHeap(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

int extractMin(int arr[], int *n) {
    int min = arr[0];
    arr[0] = arr[*n - 1];
    (*n)--;
    heapify(arr, *n, 0);
    return min;
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n], result[n];
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i);
        scanf("%d", &arr[i]);
    }

    buildMinHeap(arr, n);
    int size = n;
    for (int i = n - 1; i >= 0; i--)
        result[i] = extractMin(arr, &size);

    printf("Sorted array (Descending): ");
    for (int i = 0; i < n; i++)
        printf("%d ", result[i]);

    return 0;
}
