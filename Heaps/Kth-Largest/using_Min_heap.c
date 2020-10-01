
/****************
		ALGO:
Time complexity: O(n*log(k))
1. Construct a Min heap of of Size k 
2. Insert the first k elements of the array in the heap[0 to k-1]
3. Then for each of the remaining elements[k to n-1], if that element is greater than root, swap with root and heapify

At the ned, the heap will have k largest elements in the array.

Kth largest will be at the root.
****************/
typedef struct{
    int *arr;
    int i;
    int size;
}my_heap;

my_heap* heap_init(int k){
    my_heap* ptr=(my_heap*)malloc(sizeof(my_heap));
    ptr->i=-1;
    ptr->size=k;
    ptr->arr=(int*)malloc((ptr->size)*sizeof(int));
    
    return ptr;
}

//Min heap
void heapify_top_bottom(my_heap* h,int parent_node,int size){
    int left=(2*parent_node)+1;
    int right=(2*parent_node)+2;
    int temp;
    int min=parent_node;
    
    
    if(left<size && h->arr[left] < h->arr[parent_node]){
        min=left;
    }
    
    if(right<size && h->arr[right] < h->arr[min]){
        min=right;
    }
    
    if(min!=parent_node){
        temp=h->arr[min];
        h->arr[min]=h->arr[parent_node];
        h->arr[parent_node]=temp;
        
        heapify_top_bottom(h,min,size);
    }    
}

void heapify_bottom_top(my_heap* h,int index){
    int parent=(index-1)/2;
    if(parent>=0 && (h->arr[index] < h->arr[parent])){
        int temp=h->arr[index];
        h->arr[index]=h->arr[parent];
        h->arr[parent]=temp;
        
        heapify_bottom_top(h,parent);
    }
}

void insert(my_heap* ptr,int val){
    if(ptr->i >= ptr->size){
        printf("Overflow\n");
        return;
    }
    ptr->arr[++(ptr->i)]=val;
    heapify_bottom_top(ptr,ptr->i);
    
}


int findKthLargest(int* nums, int ns, int k){
    my_heap* h=heap_init(k);
    
    for(int i=0;i<k;i++){
        insert(h,nums[i]);
    }
    
    for(int i=0;i<k;i++){
        printf("%d",nums[i]);
    }
    
    
    for(int i=k;i<ns;i++){
        if(nums[i]>h->arr[0]){
            h->arr[0]=nums[i];
            heapify_top_bottom(h,0,k);
        }
    }
    
    return h->arr[0];
}

