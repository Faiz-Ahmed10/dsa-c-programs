
# include <stdio.h>

int linearSearch(int arr[], int size, int key);

int main(){
	int  n;
	printf("Enter the size of array : "); 
	scanf("%d", &n);

	int arr[n], i;
	printf("Enter array elements : ");
	for (i=0; i<n; i++)
		scanf("%d", &arr[i]);
	
	int key;
	printf("Enter Element to Find : ");
	scanf("%d", &key);

	int index = linearSearch(arr, n-1, key);
	if (index != -1)
		printf("Element Found at Index: %d\n", index);
	else 
		printf("Element Not found");

}

int linearSearch(int arr[], int size, int key){
	if (size < 0) 
		return -1;
	if (arr[size] == key)
		return size;
	else 
		return linearSearch(arr, size-1, key);
}

