/**************
		ALGO:
Time complexity: O(n + k*log(n))

1. Convert the incoming array to a max heap
2. Pop the first k-1 elements from it.

This will leave the k largest elements in the heap/arr.
Kth largest will be at the root.

***************/


void heapify_top_bottom(int *arr,int parent_node,int size){
    int left=(2*parent_node)+1;
    int right=(2*parent_node)+2;
    int temp;
    int max=parent_node;
    
    
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

void pop(int* arr,int size){
    
    arr[0]=arr[size-1];
    heapify_top_bottom(arr,0,size-1);
}


int findKthLargest(int* nums, int ns, int k){
    if(ns<k) return -1;
    
    if(ns==1){
        return nums[0];
    }
    
    for(int i=(ns/2)-1;i>=0;i--){
        heapify_top_bottom(nums,i,ns);
    }

    
    for(int i=1;i<k;i++){
        pop(nums,(ns-i+1));
    }

    for(int i=0;i<ns;i++)
        printf("%d",nums[i]);
    
    return nums[0];
    
}
