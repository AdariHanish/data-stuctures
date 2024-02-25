#include <stdio.h>
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(int arr[], int low, int high) {
    int pivot = arr[high];

    int i = (low - 1);

    for (int j = low; j <= high; j++) {
        if (arr[j] < pivot) {
        
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {

    if (low < high) {
    
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    quickSort(arr, 0, n - 1);
    printf("Sorted Array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

//Algorithm
/*The logic is simple, we start from the leftmost element and keep track of the index of smaller (or equal) elements as i. While traversing, if we find a smaller element, we swap the current element with arr[i]. Otherwise, we ignore the current element.

Let us understand the working of partition and the Quick Sort algorithm with the help of the following example:

Consider: arr[] = {10, 80, 30, 90, 40}.

Compare 10 with the pivot and as it is less than pivot arrange it accrodingly.
Partition in QuickSort: Compare pivot with 10
Partition in QuickSort: Compare pivot with 10

Compare 80 with the pivot. It is greater than pivot.
Partition in QuickSort: Compare pivot with 80
Partition in QuickSort: Compare pivot with 80

Compare 30 with pivot. It is less than pivot so arrange it accordingly.
Partition in QuickSort: Compare pivot with 30
Partition in QuickSort: Compare pivot with 30

Compare 90 with the pivot. It is greater than the pivot.
Partition in QuickSort: Compare pivot with 90
Partition in QuickSort: Compare pivot with 90

Arrange the pivot in its correct position.
Partition in QuickSort: Place pivot in its correct position
Partition in QuickSort: Place pivot in its correct position*/
