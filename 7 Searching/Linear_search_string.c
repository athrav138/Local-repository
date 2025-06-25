#include <stdio.h>

void search(char arr[], int n, char ch);

int main() {
    int n, i, count = 0;
    char ch;

    printf("Enter the size of string you want to declare.: ");
    scanf("%d", &n);

    char arr[n];
    printf("Enter string: ");
    scanf("%s", arr);

    printf("Entered array:\n");
    for (i = 0; i < n; i++) {
        printf("%c ", arr[i]);
    }

    // Fix: clear newline left in buffer
    while (getchar() != '\n');

    // Character input by user
    printf("\nEnter character you want to search in string: ");
    scanf("%c", &ch);

    search(arr, n, ch);
    return 0;
}

void search(char arr[], int n, char ch) {
    int count = 0, i;
    for (i = 0; i < n; i++) {
        if (arr[i] == ch) {
            printf("\n%c is the character found in %d position\n", ch, i);
            count++;
        }
    }

    if (count == 0) {
        printf("\n%c is the character not found in string.\n", ch);
    }
}
