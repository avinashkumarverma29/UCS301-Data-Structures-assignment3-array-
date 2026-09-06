#include <stdio.h>

#define MAX 100

// Function to store elements in the 1D array (Row-Major Mapping)
void storeLowerTriangular(int n, int matrix[MAX][MAX], int flatArray[]) {
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= j) {
                // Mapping formula for lower triangular matrix (0-indexed)
                flatArray[k++] = matrix[i][j];
            }
        }
    }
}

// Function to retrieve an element at (i, j)
int getElement(int flatArray[], int i, int j) {
    if (i >= j) {
        // Using formula: index = i*(i+1)/2 + j
        int index = (i * (i + 1)) / 2 + j;
        return flatArray[index];
    } else {
        return 0; // Elements above main diagonal are zero
    }
}

int main() {
    int n;
    printf("Enter the order of the square matrix (N): ");
    scanf("%d", &n);

    int matrix[MAX][MAX];
    printf("Enter the elements of the %dx%d matrix:\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Size of 1D array required is N*(N+1)/2
    int size = (n * (n + 1)) / 2;
    int flatArray[MAX];

    storeLowerTriangular(n, matrix, flatArray);

    printf("\nEfficiently stored 1D Array (Row-Major):\n[ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", flatArray[i]);
    }
    printf("]\n");

    // Example retrieval
    int r, c;
    printf("\nEnter row and column index to fetch element (0-indexed): ");
    scanf("%d %d", &r, &c);
    
    printf("Element at (%d, %d) is: %d\n", r, c, getElement(flatArray, r, c));

    return 0;
}