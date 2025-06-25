#include <stdio.h>

int main() {
    int arr[100], temp[100];
    int n, i, mid, l, h, k, a, b, size;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for(i = 0; i < n; i++) {
        printf("Enter %d element: ", i);
        scanf("%d", &arr[i]);
    }

    for(size = 1; size < n; size = size * 2) {
        for(i = 0; i < n; i = i + 2 * size) {
            l = i;
            mid = i + size - 1;
            h = i + 2 * size - 1;

            if(mid >= n)
                mid = n - 1;
            if(h >= n)
                h = n - 1;

            a = l;
            b = mid + 1;
            k = l;

            while(a <= mid && b <= h) {
                if(arr[a] < arr[b])
                    temp[k++] = arr[a++];
                else
                    temp[k++] = arr[b++];
            }

            while(a <= mid)
                temp[k++] = arr[a++];

            while(b <= h)
                temp[k++] = arr[b++];
        }

        for(i = 0; i < n; i++)
            arr[i] = temp[i];
    }

    printf("Array after merge sort in ascending order:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

return 0;
}
