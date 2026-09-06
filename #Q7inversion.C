#include <stdio.h>

// Function to merge two halves and count inversions
long long merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left;    // Starting index for left subarray
    int j = mid + 1; // Starting index for right subarray
    int k = left;    // Starting index to be sorted
    long long inversionCount = 0;

    while ((i <= mid) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            // If arr[i] > arr[j], then all elements from i to mid 
            // are greater than arr[j] (since the array is sorted)
            temp[k++] = arr[j++];
            inversionCount += (mid - i + 1);
        }
    }

    // Copy the remaining elements of left subarray
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // Copy the remaining elements of right subarray
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copy sorted elements back into the original array
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return inversionCount;
}

// Recursive function to divide the array and count inversions
long long mergeSort(int arr[], int temp[], int left, int right) {
    long long inversionCount = 0;
    if (right > left) {
        int mid = left + (right - left) / 2;

        inversionCount += mergeSort(arr, temp, left, mid);
        inversionCount += mergeSort(arr, temp, mid + 1, right);

        inversionCount += merge(arr, temp, left, mid, right);
    }
    return inversionCount;
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d real numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int temp[n];
    long long totalInversions = mergeSort(arr, temp, 0, n - 1);

    printf("Total number of inversions: %lld\n", totalInversions);

    return 0;
}