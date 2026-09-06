#include <stdio.h>
#define MAX 100

int main() {
    int n;
    printf("Enter the order of the matrix (N): ");
    scanf("%d", &n);

    // Size for tridiagonal is 3n - 2
    int size = 3 * n - 2;
    int tri[size];

    printf("Enter the tridiagonal elements (lower, main, upper sequentially):\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &tri[i]);
    }

    printf("\nReconstructed Tri-diagonal Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i - j == 1) // Sub-diagonal
                printf("%d ", tri[i - 1]);
            else if (i == j) // Main diagonal
                printf("%d ", tri[n + i - 1]);
            else if (j - i == 1) // Super-diagonal
                printf("%d ", tri[2 * n + i - 1]);
            else
                printf("0 ");
        }
        printf("\n");
    }
    return 0;
}