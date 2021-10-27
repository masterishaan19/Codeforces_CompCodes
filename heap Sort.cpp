#include <stdio.h>
#include<stdlib.h>
void heapSort (int arr[], int n);
void adjust (int arr[], int n, int i);
void swap (int *x, int*y);
int main()
{
	int i,n;
	printf("Enter no of elements : ");
	scanf("%d", &n);
    int arr[n+1];
    arr[0] = 0;
	printf("Enter the values\n");
	for(i=1; i<=n; i++)
	     scanf("%d", &arr[i]);
	heapSort(arr, n);
	printf("The sorted array is \n");
	for(i=1; i<=n; i++)
	      printf("%d ", arr[i]);
	return 0;
}
void heapSort (int arr[], int n)
{
	int i;
	for (i=n/2; i>=1; i--)
		adjust (arr, n, i);		
	for (i=n; i>=2; i--)
	{
		swap (&arr[1], &arr[i]);
		adjust(arr,i-1,1);
	}
}
void adjust (int arr[], int n, int i)
{
	if (i <= n/2)
	{
	    int index;	
		index = 2*i;
		if ( 2*i+1 <= n && arr[2*i+1] > arr[2*i])
			index = 2*i+1;
		if (arr[i] < arr[index])
		{
			swap (&arr[i], &arr[index]);
			adjust(arr, n, index);
		}
	}
}
void swap (int *x, int*y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
