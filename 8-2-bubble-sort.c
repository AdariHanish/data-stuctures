#include <stdio.h>
void bubbleSort(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int x;
    printf("enter the size of array:");
    scanf("%d",&x);
    int array[x];
    printf("enter the elements of array:");
    for(int i=0;i<x;i++)
    {
        scanf("%d",&array[i]);
    }
    int size = sizeof(array) / sizeof(array[0]);
    printf("Original array: \n");
    printArray(array, size);
    bubbleSort(array, size);
    printf("Sorted array: \n");
    printArray(array, size);
    return 0;
}
