#include <stdio.h>

void merge(int* arr,int low,int mid,int high){
	int n1 = mid - low+1;
	int n2 = high - mid;
	
	int L[n1];
	int R[n2];
	
	int i=0,j=0;
	for (i = 0; i < n1; i++)  
        L[i] = arr[low + i];  
    for (j = 0; j < n2; j++)  
        R[j] = arr[mid + 1 + j]; 
	
	int k=low;
	i=0;j=0;
	while(i<n1 && j<n2){
		if(L[i]<=R[j]){
			arr[k]=L[i++];
		} else{
			arr[k]=R[j++];
		}
		k++;
	}
	
	while(i<n1){
		arr[k++]=L[i++];
	}
	
	while(j<n2){
		arr[k++]=R[j++];
	}
	
}


void mergeSort(int* arr,int l,int h){
	if(l<h){
		int m=l+(h-l)/2;
		
		mergeSort(arr,l,m);
		mergeSort(arr,m+1,h);
		
		merge(arr,l,m,h);
	}
	
}

void printArr(int* arr,int size){
	int i=0;
	for(;i<size;i++)
		printf("%d ",arr[i]);
}

int main(void){
	
	int arr[10]={9,7,6,3,4,2,5,1,0,8};
	int size=sizeof(arr)/sizeof(arr[0]);
	
	mergeSort(arr,0,size-1);
	
	printArr(arr,size);
	
	return 0;
}
