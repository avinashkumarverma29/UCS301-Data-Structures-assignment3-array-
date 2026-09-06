#include <stdio.h>

int findMissingBinary(int arr[], int size) {
    int low = 0, high = size - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        // If the element value is greater than its expected value (index + 1),
        // the missing number is on the left side.
        if (arr[mid] > mid + 1) {
            // Check if this is the first discrepancy
            if (mid == 0 || arr[mid - 1] == mid) {
                return mid + 1;
            }
            high = mid - 1;
        } else {
            // Otherwise, the missing number is on the right side.
            low = mid + 1;
        }
    }
    
    // If no number is missing in between, the missing number is n
    return size + 1;
}

int main() {
    int n;
    printf("Enter the value of n (range 1 to n): ");
    scanf("%d", &n);
    
    int size = n - 1;
    int arr[size];
    printf("Enter %d sorted elements (distinct integers): \n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    int missing = findMissingBinary(arr, size);
    printf("The missing number (Binary Search) is: %d\n", missing);
    
    return 0;
}