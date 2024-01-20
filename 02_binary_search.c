#include<stdio.h>

int binarySearch(int arr[], int size, int key) {
    int low, mid, high, i;
    low = 0;
    high = size-1;
    while(low<=high) {
        mid = (low+high)/2;
        if(arr[mid] == key) {
            return mid;
        }
        else if(arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}

int main(){
    int arr[20], i, size, key;

    printf("Enter the size of array:");
    scanf("%d", &size);

    printf("Enter array elements:\n");
    for(i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter key to be searched:");
    scanf("%d", &key);
    int pos = binarySearch(arr, size, key);

    if(pos == -1) {
        printf("key element %d not found", key);
    }
    else {
        printf("key element %d found at postion %d", key, pos+1);
    }
    
    return 0;
}
