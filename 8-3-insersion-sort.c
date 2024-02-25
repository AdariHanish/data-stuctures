#include <stdio.h>
void insertionSort(int array[], int size) {
    int i, key, j;
    for (i = 1; i < size; i++) {
        key = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
} 
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
int main() {
    int y;
    printf("enter the size of the array:");
    scanf("%d",&y);
    int array[y];
    printf("enter the elements of the array:");
    for(int i=0;i<y;i++)
    {
        scanf("%d",&array[y]);
    }
    int size = sizeof(array) / sizeof(array[0]);
    printf("Original array: \n");
    printArray(array, size);
    insertionSort(array, size);
    printf("Sorted array: \n");
    printArray(array, size);
    return 0;
}
