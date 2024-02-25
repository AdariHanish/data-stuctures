#include <stdio.h>
void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;
    
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int a;
    printf("enter the size of the array:");
    scanf("%d",&a);
    int arr[a];
    printf("enter the elements of the array:");
    for(int i=0;i<a;i++)
    {
       scanf("%d",&arr[i]);
    }
    printf("Array before sorting: \n");
    printArray(arr, a);
    selectionSort(arr, a);
    printf("Array after sorting: \n");
    printArray(arr, a);
    return 0;
}
