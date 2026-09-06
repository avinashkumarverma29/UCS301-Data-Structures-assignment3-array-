#include <stdio.h>
#define MAX 100

int main() {
    int n;
    printf("Enter the order of the matrix (N): ");
    scanf("%d", &n);

    int size = (n * (n + 1)) / 2;
    int lower[size];

    printf("Enter %d elements for the lower triangular part (row-major):\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &lower[i]);
    }

    printf("\nReconstructed Lower Triangular Matrix:\n");
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= j)
                printf("%d ", lower[k++]);
            else
                printf("0 ");
        }
        printf("\n");
    }
    return 0;
}