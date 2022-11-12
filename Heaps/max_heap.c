#include <stdio.h>
#include <stdlib.h>

void max_heapify(int arr[], int i, int n) {
    int left = 2*i + 1;
    int right = 2*i + 2;
    int largest = i;
    if (left < n && arr[largest] < arr[left]) {
        largest = left;
    };

    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    };

    if (largest!= i)
    {
        int temp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = temp;

        max_heapify(arr, largest, n);
    }
    
};

void buildHeap(int arr[], int s) {
    int i;
    for (i = s/2; i >= 0; i--)
    {
        max_heapify(arr, i, s);
    }
    
};


int main() {
    int arr[7] = {5, 7, 6, 3, 2, 4, 8};
    buildHeap(arr, 7);
    for (int j = 0; j < 7; j++)
    {
        printf("%d \n", arr[j]);
    }
    return 0;
};