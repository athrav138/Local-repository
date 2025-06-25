#include <stdio.h>

int getMax(int arr[], int n) {
    int max = arr[0];
    for(int i = 1; i < n; i++)
        if(arr[i] > max)
            max = arr[i];
    return max;
}

void countingSortDescending(int arr[], int n, int exp) {
    int output[n]; 
    int count[10] = {0};

    // Count occurrences of digits
    for(int i = 0; i < n; i++)
        count[(arr[i]/exp)%10]++;

    // Modify count for descending order
    for(int i = 8; i >= 0; i--)
        count[i] += count[i + 1];

    // Build output array (stable)
    for(int i = n - 1; i >= 0; i--) {
        int digit = (arr[i]/exp)%10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy to original array
    for(int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSortDescending(int arr[], int n) {
    int max = getMax(arr, n);

    for(int exp = 1; max/exp > 0; exp *= 10)
        countingSortDescending(arr, n, exp);
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];

    for(int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    radixSortDescending(arr, n);

    printf("Sorted array (Descending): ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
