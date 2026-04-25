Q112: Write a program to take an integer array arr as input. The task is to find the maximum sum of any contiguous subarray using Kadane's algorithm. Print the maximum sum as output. If all elements are negative, print the largest (least negative) element.

/*
Sample Test Cases:
Input 1:
arr[] = [2, 3, -8, 7, -1, 2, 3]
Output 1:
11

Input 2:
arr[] = [-2, -4]
Output 2:
-2

Input 3:
arr[] = [5, 4, 1, 7, 8]
Output 3:
25

*/

#include <stdio.h>

int main() {
    int n;

    // Input array size
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max_so_far = arr[0];
    int current_max = arr[0];

    // Kadane’s Algorithm
    for (int i = 1; i < n; i++) {
        // Either start new subarray at current element or extend the existing one
        if (current_max + arr[i] > arr[i])
            current_max = current_max + arr[i];
        else
            current_max = arr[i];

        // Update the overall maximum sum
        if (current_max > max_so_far)
            max_so_far = current_max;
    }

    printf("Maximum subarray sum: %d\n", max_so_far);
    return 0;
}
