#include <stdio.h>
#define MAX 100

int main() {
    int n;
    printf("Enter the order of the symmetric matrix (N): ");
    scanf("%d", &n);

    int size = (n * (n + 1)) / 2;
    int sym[size];

    printf("Enter %d elements for the lower triangular part:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &sym[i]);
    }

    printf("\nReconstructed Symmetric Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int r = (i >= j) ? i : j;
            int c = (i >= j) ? j : i;
            int index = (r * (r + 1)) / 2 + c;
            printf("%d ", sym[index]);
        }
        printf("\n");
    }
    return 0;
}
