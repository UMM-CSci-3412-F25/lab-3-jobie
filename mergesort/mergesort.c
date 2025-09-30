#include "mergesort.h"
#include <stdlib.h>

void merge(int left, int mid, int right, int values[]) {
    /*
    @Param left: starting index of the left subarray
    @Param mid: starting index of the right subarray
    @Param right: ending index of the right subarray
    @Param values: the array containing the subarrays to be merged

    @Returns void

    Merge two sorted subarrays into a single sorted array.
    */
    int N1 = mid - left;
    int N2 = right - mid;
    int* left_arr = (int*) calloc(N1, sizeof(int));
    int* right_arr = (int*) calloc(N2, sizeof(int));

    for (int i = 0; i < N1; i++) left_arr[i] = values[left + i];
    for (int j = 0; j < N2; j++) right_arr[j] = values[mid + j];
    int i = 0, j = 0, k = left;
    while (i < N1 && j < N2) {
        if (left_arr[i] <= right_arr[j]) {
            values[k++] = left_arr[i++];
        } else {
            values[k++] = right_arr[j++];
        }
    }
    while (i < N1) values[k++] = left_arr[i++];
    while (j < N2) values[k++] = right_arr[j++];
    free(left_arr);
    free(right_arr);
}

void mergesort_helper(int left, int right, int values[]) {
    /*
    @Param left: starting index of the left subarray
    @Param right: ending index of the right subarray
    @Param values: the array containing the subarrays to be merged

    @Returns void

    Recursively split the array into smaller subarrays and merge them.
    */
    if (right - left <= 1) return;
    int mid = left + (right - left) / 2;

    int* left_half = (int*) calloc((mid - left), sizeof(int));
    int* right_half = (int*) calloc((right - mid), sizeof(int));
    for (int i = left; i < mid; i++) left_half[i - left] = values[i];
    for (int i = mid; i < right; i++) right_half[i - mid] = values[i];

    mergesort_helper(left, mid, values);
    mergesort_helper(mid, right, values);

    merge(left, mid, right, values);
    free(left_half);
    free(right_half);
}

void mergesort(int size, int values[]) {
    /*
    @Param size: the number of elements in the array
    @Param values: the array to be sorted

    @Returns void

    Sorts the provided "values" array in place.
    */
    mergesort_helper(0, size, values);
}