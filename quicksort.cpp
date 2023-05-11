#include <stdio.h>
void swap(int* a, int* b) 
{
	int t = *a;
	*a = *b;
	*b = t;
}
int partition(int arr[], int p, int r) 
{
	int pivot = arr[r];
	int i = (p-1);

	for (int j = p; j<= r-1; j++) 
	{
		if (arr[j] < pivot) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[r]);
	return (i + 1);
}
void quickSort(int arr[], int p, int r) 
{
	if (p < r) 
	{
		int pivot = partition(arr, p, r);
		quickSort(arr, p, pivot - 1);
		quickSort(arr, pivot + 1, r);
	}
}
void printArray(int arr[], int size) 
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
int main() 
{
	int arr[] = {25,12,9,18,50,45,30,63,33};
	int n = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr, 0, n - 1);
	printf("Sorted array: \n");
	printArray(arr, n);
	return 0;
}

