#include<stdio.h>
void merge(int arr[], int start, int mid, int end)
{
	int len = end -start +1;
	int temp[len];
	int i = start;
	int j = mid+1;
	int k = 0;
	while(i <= mid && j<= end)
	{
		if(arr[i] <= arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}
	while(i <= mid)
	{
		temp[k++] = arr[i++];
	}
	while(j <= end)
	{
		temp[k++] = arr[j++];
	}
	k =0;
	for(int i=start; i<=end; i++)
	{
		arr[i] = temp[k++];
	}
}
void msort(int arr[], int start, int end)
{
	if(start < end)
	{
		int mid = (start + end)/2;
		msort(arr, start, mid);
		msort(arr, mid+1, end);
		merge(arr, start, mid, end);
	}
}
int main()
{
	int num;
	printf("Enter number of terms:");
	scanf("%d",&num);
	int arr[num];
	for(int i=0; i<num; i++)
		scanf("%d",&arr[i]);
	int start = 0;
	int end = num-1;
	msort(arr, start, end);
	printf("Your sorted array is:");
	for(int i=0; i<num; i++)
		printf("%d ",arr[i]);
}
