/*
    @file
    @brief [Bubble Sort](https://en.wikipedia.org/wiki/Bubble_sort) algorithm
    implementation
*/
#include<assert.h>
#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*
    Display elements of array
    @param arr array to be display
    @param n length of array
*/
void display(const int* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/*
    swap two values by using pointer
    @param first first pointer of first number
    @param second second pointer of second number
*/
void swap(int* first, int* second) {
    int temp = *first;
    *first = *second;
    *second = temp;
}

/*
    Bubble sort algorithm implementation
    @param arr array to be sorted
    @param size size of array
*/
void bubbleSort(int* arr, int size) {
    for (int i = 0; i < size-1; i++) {  
        /* for each array index */
        bool swapped = false;   /* flag to check if any changes had to be made */
        /* perform iterations until no more changes were made or outer loop
            executed for all array indices */
        for (int j = 0; j < size-1-i; j++) {    
            /* for each element in the array */
            if (arr[j] > arr[j+1]) {
                /* if the order of successive elements needs update */
                swap(&arr[j], &arr[j+1]);
                swapped = true; /* set flag */
            }
        }
        if(!swapped) {
            /* since no more updates we made, the array is already sorted
                this is an optimization for early termination */
            break;
        }
    }   /* end of oputer for */
}

/*
    Test Function
*/
void test() {
    const int size = 1000;
    int *arr = (int *) calloc(size, sizeof(int));

    /* generate size random numbers from 0 to 100 */
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }

    // printf("\nBefore sorting: ");
    // display(arr, size);

    /* Start time measurement */
    clock_t start = clock();
    
    bubbleSort(arr, size);
    
    /* End time measurement */
    clock_t end = clock();
    
    /* Calculate the time difference in seconds */
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    // printf("\nAfter sorting: ");
    // display(arr, size);

    /* Print the time taken */
    printf("\nBubble sort took %f seconds to execute \n", time_taken);

    /* we use assert to check if my array is sorted or not */
    for (int i = 0; i < size-1; i++) {
        assert(arr[i] <= arr[i+1]);
    }
    free(arr);
}

/* Driver code */
int main() {
    /* Initializes random number generator */
    srand(time(NULL));
    test();
    return 0;
}

/*
1. Bubble Sort - 🍋‍🟩
2. Selection Sort
3. Insertion Sort
4. Quick Sort
5. Merge Sort
*/