#ifndef ALG_009_SORTING_H
#define ALG_009_SORTING_H

// Utility function to swap to values
void swap(int *a, int *b);

// Bubble sort
void bubbleSort(int arr[], int n);

// Selection sort
void selectionSort(int arr[], int n);

// Insertion sort
void insertionSort(int arr[], int n);

// Merge sort
void merge(int arr[], int l, int m, int r);

void mergeSort(int arr[], int l, int r);

// Quick sort
int partition(int arr[], int low, int high);

void quickSort(int arr[], int low, int high);

#endif //ALG_009_SORTING_H
