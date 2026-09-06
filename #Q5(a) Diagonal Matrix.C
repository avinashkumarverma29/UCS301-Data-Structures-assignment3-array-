#include <stdio.h>
#define MAX 100

int main() {
    int n, diag[MAX];
    printf("Enter the order of the matrix (N): ");
    scanf("%d", &n);

    printf("Enter %d diagonal elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &diag[i]);
    }

    printf("\nReconstructed Diagonal Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                printf("%d ", diag[i]);
            else
                printf("0 ");
        }
        printf("\n");
    }
    return 0;
}