#include <stdio.h>
#include <stdio.h>

void print_heap(int* arr,int size){
	int i=0;
	for(;i<size;i++){
		printf("%d\t",arr[i]);
	}
	printf("\n");
}

void heapify_top_bottom(int* arr,int parent_node,int size){
	int left=(2*parent_node)+1;
	int right=(2*parent_node)+2;
	int max=parent_node;
	int temp;
	
	if(left<size && arr[left] > arr[parent_node]){
		max=left;
	}
	if(right<size && arr[right] > arr[max]){
		max=right;
	}
	
	if(max!=parent_node){
		temp=arr[max];
		arr[max]=arr[parent_node];
		arr[parent_node]=temp;
		
		heapify_top_bottom(arr,max,size);
	}
	
}

/********************
Algo:
Loop 1: First convert incoming array to MAX-heap
Loop 2: Start from last element; Swap last element with first and convert that to max heap=> largest element will be at the end now
Iteratively do this till i>0. Kinda imagine this as bubbleSort==> after each iteration, the largest element bubbles to the end.
Time Complexity: O(nlogn)=>n for creating heap & (log n) for heapify
*********************/
void heapSort(int *arr,int size){
	int i=(size/2)-1;
	for(;i>=0;i--){
		heapify_top_bottom(arr,i,size);
	}
	print_heap(arr,size);
	i=size-1;
	printf("During Heap Sort:\n");
	for (;i>0;i--) 
    { 
    	print_heap(arr,i+1);
        // Move current root to end 
        int temp=arr[0];
        arr[0]=arr[i];
        arr[i]=temp;
  
        // call max heapify on the reduced heap 
        heapify_top_bottom(arr, 0, i); 
    } 
	printf("Done\n");	
}


int main(void){
	
	int arr[]={4,3,5,10,7,6};
	
	int size=sizeof(arr)/sizeof(arr[0]);
	
	print_heap(arr,size);
	
	heapSort(arr,size);
	
	print_heap(arr,size);	
	return 0;
}
