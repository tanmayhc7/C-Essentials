//Pivot element as last

#include <stdio.h>

void swap(int* a,int* b){
	int temp=*a;
	*a=*b;
	*b=temp;
}

int partition(int* arr,int l,int h){
	int i=l-1,j;
	int pivot=arr[h];
	
	for(j=l;j<h;j++){
		if(arr[j]<pivot){
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[h]);
	return i+1;
	
}

void quicksort(int *arr,int low,int high){
	if(low<high){
		int pi=partition(arr,low,high);
		
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

