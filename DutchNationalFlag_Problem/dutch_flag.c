#include <stdio.h>
#include <stdlib.h>

void dutchNationalFlag(int* arr, int size, int key)
{
	int low=0, mid=0, high=size-1;
	if (size <= 0 || key < 0 || key > size){
	    printf("Invalid Array\n");
	    return;
  	  }
	int pivot = arr[key];
	while (mid < high)
	  {
	    if (arr[mid] > pivot)
	    {
	      swap(&arr[high], &arr[mid]);
	      high--;
	    }
	    else if (arr[mid] == pivot)
	    {
	      mid++;
	    }
	    else
	    {
	      swap(&arr[mid], &arr[low]);
	      low++;
	      mid++;
	    }
	  }
}

void printArr(int *arr,int size){
	for(int i=0;i<size;i++)
		printf("%d\t",arr[i]);
}

void swap(int *x, int *y)
{
  int tmp;
  tmp  = *x;
  *x = *y;
  *y = tmp;
}

int main(void){
	time_t t;   
	srand((unsigned) time(&t));

	int arr[] = {1, 4, 1, 5, 7, 2, 4, 9, 5, 10, 3};
	int size=sizeof(arr)/sizeof(arr[0]);
	int pivot = rand()%size;
	printf("pivot:%d\n",pivot);
	dutchNationalFlag(&arr,size, pivot);
	printArr(&arr, size);
	return 0;
}
