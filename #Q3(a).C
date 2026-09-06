#include <stdio.h>

int findMissingLinear(int arr[], int n) {
    // The expected sum of numbers from 1 to n
    int totalSum = (n * (n + 1)) / 2;
    int actualSum = 0;
    
    // There are n-1 elements in the array
    for (int i = 0; i < n - 1; i++) {
        actualSum += arr[i];
    }
    
    return totalSum - actualSum;
}

int main() {
    int n;
    printf("Enter the value of n (range 1 to n): ");
    scanf("%d", &n);
    
    int arr[n - 1];
    printf("Enter %d sorted elements (distinct integers): \n", n - 1);
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &arr[i]);
    }
    
    int missing = findMissingLinear(arr, n);
    printf("The missing number (Linear Time) is: %d\n", missing);
    
    return 0;
}