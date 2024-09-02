#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void parallelMergeSort(int arr[], int left, int right, int depth) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        if (depth > 0) {
            #pragma omp parallel sections
            {
                #pragma omp section
                {
                    parallelMergeSort(arr, left, mid, depth - 1);
                }
                #pragma omp section
                {
                    parallelMergeSort(arr, mid + 1, right, depth - 1);
                }
            }
        } else {
            parallelMergeSort(arr, left, mid, 0);
            parallelMergeSort(arr, mid + 1, right, 0);
        }

        merge(arr, left, mid, right);
    }
}

int main() {
    int n = 100000;
    int *arr = malloc(n * sizeof(int));


    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }

    int depth = omp_get_max_threads();
    double start_time = omp_get_wtime();
    
    
    parallelMergeSort(arr, 0, n - 1, depth);
    
    double end_time = omp_get_wtime();
    
    printf("Time taken: %f seconds\n", end_time - start_time);

    
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
   

    free(arr);
    return 0;
}
