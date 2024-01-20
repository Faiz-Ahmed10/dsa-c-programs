#include<stdio.h>

void selectionSort(int a[], int size) {
    int i, j, t, minIndex;
    for(i = 0; i < size-1; i++) {
        minIndex=i;
        for(j = i+1; j < size; j++) {
            if(a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
        t = a[i];
        a[i] = a[minIndex];
        a[minIndex] = t;
    }
}

int main(){
    int arr[20], size, i;

    printf("Enter size of array:");
    scanf("%d", &size);

    printf("Enter array elements:\n");
    for(i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Before sorting...\n");
    for(i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    selectionSort(arr, size);

    printf("\nAfter sorting...\n");
    for(i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
