#include <stdio.h>

void bubbleSort(int arr[], int n);

int main() {
    int  n;
    printf("Enter the size of array : "); 
    scanf("%d", &n);

    int arr[n];
    printf("Enter array elements : ");
    for (int i=0; i<n; i++)
	scanf("%d", &arr[i]);

    bubbleSort(arr, n);
    printf("Sorted Array: \n");
    for (int i=0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void bubbleSort(int arr[], int n) {
    int temp;
    for (int i=0; i<n-1 ; i++){
        for (int j=0; j < n-1-i; j++){
            if (arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

