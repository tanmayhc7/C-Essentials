#include <stdio.h>

int removeDup(int* arr,int size){
	if(size<=1) return size;
	
	//store index of unique element
	int j=0;
	
	int i=0;
	for(;i<size-1;i++){
		// If current element is not equal to next element then store that current element 
		if(arr[i]!=arr[i+1]){
			arr[j++]=arr[i];	
		}
	}
	//Store the last element
	arr[j++] = arr[size-1];
	
	return j;
}

void printArr(int* arr,int size){
	int i=0;
	for(;i<size;i++){
		printf("%d\t",arr[i]);
	}
	printf("\n");
}

int main(void){
	
	int arr[]={1,2,2,3,3,3,4,4,4,4,5,5,5,5,5,6};
	int size=sizeof(arr)/sizeof(arr[0]);
	
	printf("Old Array: \t");
	printArr(arr,size);
	
	int new_size=removeDup(arr,size);
	
	printf("New Array: \t");
	printArr(arr,new_size);
	
	return 0;
}
