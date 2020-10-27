#include <stdio.h>

void swap(int* a,int* b){
	int temp=*a;
	*a=*b;
	*b=temp;
}

int partition(int* arr,int low,int high){
	int i, j, pivot;
	pivot=arr[low];
	i=low;
	j=high;
	
	while(i<j){
	 while(arr[i]<=pivot && i<high)
	    i++;
	 while(arr[j] > pivot)
	    j--;
	 if(i<j){
	    swap(&arr[i],&arr[j]);
	 }
	}
	
	swap(&arr[j],&arr[low]);	
	return j;		
}

void quicksort(int* arr,int low,int high){
   
   if(low < high){   		
	int pi = partition(arr,low,high);
	
	quicksort(arr,low,pi-1);
	quicksort(arr,pi+1,high);
   }
}

void print(int* arr,int size){
	int i;
	for(i=0;i<size;i++)
		printf("%d\t",arr[i]);
	printf("\n");
}

int main(void){
	
	int arr[]={9,4,3,6,7,2,1,8};
	int size=sizeof(arr)/sizeof(arr[0]);
	
	quicksort(arr,0,size-1);
	print(arr,size);
	
	return 0;
}

