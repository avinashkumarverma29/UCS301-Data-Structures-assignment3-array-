#include <stdio.h>
#include <string.h>

int main() {
    int n;
    printf("Enter the number of strings: ");
    scanf("%d", &n);
    getchar(); // Consume newline buffer
    
    char arr[n][100];
    printf("Enter %d strings:\n", n);
    for (int i = 0; i < n; i++) {
        fgets(arr[i], sizeof(arr[i]), stdin);
        arr[i][strcspn(arr[i], "\n")] = 0;
    }
    
    // Bubble sort to order strings alphabetically
    char temp[100];
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp);
            }
        }
    }
    
    printf("\nStrings in alphabetical order:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
    }
    
    return 0;
}