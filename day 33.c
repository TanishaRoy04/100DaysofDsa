Q65: Search in a sorted array using binary search.

/*
Sample Test Cases:
Input 1:
5
1 3 5 7 9
7
Output 1:
Found at index 3

Input 2:
5
1 3 5 7 9
6
Output 2:
-1

*/

#include <stdio.h>

int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;  // found
        else if (arr[mid] < target)
            left = mid + 1;  // search right half
        else
            right = mid - 1; // search left half
    }

    return -1; // not found
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int target;
    scanf("%d", &target);

    int result = binarySearch(arr, n, target);

    if (result != -1)
        printf("Found at index %d\n", result);
    else
        printf("-1\n");

    return 0;
}

 