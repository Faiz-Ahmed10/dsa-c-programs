#include<stdio.h>

int linearSearch(int arr[], int size, int key) {
    int i;
    for(i = 0; i < size; i++) {
        if(arr[i] == key) {
            return i;
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
    int pos = linearSearch(arr, size, key);

    if(pos == -1) {
        printf("key element %d not found\n", key);
    }
    else {
        printf("key element %d found at postion %d\n", key, pos+1);
    }
    
    return 0;
}
