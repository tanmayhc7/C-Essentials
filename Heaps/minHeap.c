#include <stdio.h>
#include <stdlib.h>

static const heap_size=10;

typedef struct{
	int *arr;
	int size;
	int iterator;
}heap;

heap* init_heap(void){
	heap* h=(heap*)malloc(sizeof(heap));
	if(!h){
		printf("Heap pointer not allocated\n");
		return;
	}
	h->size=heap_size;
	h->arr=(int*)malloc((h->size)*sizeof(int));
	if(!h->arr){
		printf("Heap array not allocated\n");
		return;
	}
	h->iterator=-1;
	return h;
}

// HEAP INSERTION FUNCTIONS

/****************
Index passed first is the index of the new node being inserted.
Compare this value with its parent and swap if necessary
Recursively do this by passing value of parent_node to check with its parent

Since, each element at start is inserted at the bottom of the array/heap and then checking is done till the top, Insertion into a heap uses a bottom top approach
*****************/
void heapify_bottom_top(heap* h,int index){
	int temp;
	int parent_node=(index-1)/2;
	if(h->arr[index] < h->arr[parent_node]){
		//swap values at index & parent node
		temp=h->arr[index];
		h->arr[index]=h->arr[parent_node];
		h->arr[parent_node]=temp;
		heapify_bottom_top(h,parent_node);
	}
}

void insert(heap* h,int val){
	if(h->iterator < h->size){
		h->iterator++;
		h->arr[h->iterator]=val;
		heapify_bottom_top(h,h->iterator);
	} else{
		printf("Heap Full\n");
	}
	
}

//HEAP EXTRACTION FUNCTIONS

/************************
As the minimum is always at the top of the heap, Extraction always happens at the top.==>Hence the Top-Bottom approach
Then we have to recursively make each tree and subtree follow the rules of a min-heap.
So, First check compare the value of at the parent node with its children.
If any of the children has a value lesser than the parent, swap that value with the parent. 
Recursively do this by sending the value if min index (i.e. now (if swapped) parent value will be at index "min")
************************/
void heapify_top_bottom(heap* h,int parent_node){
	int left=(2*parent_node)+1;
	int right=(2*parent_node)+2;
	int min=parent_node;
	int temp;
	
	if(left<=h->iterator && h->arr[left] < h->arr[parent_node]){
		min=left;
	}
	if(right<=h->iterator && h->arr[right] < h->arr[min]){
		min=right;
	}
	
	if(min!=parent_node){
		temp=h->arr[parent_node];
		h->arr[parent_node]=h->arr[min];
		h->arr[min]=temp;
		
		heapify_top_bottom(h,min);
	}
}
/*
Put min_value(root_node) as the value of the last child and decrease the counter and call top-bottom
*/
void pop_min(heap* h){
	if(h->iterator<0){
		printf("Heap Empty\n");
		return;
	}
	
	int pop_value = h->arr[0];
	h->arr[0]=h->arr[h->iterator];
	h->iterator--;
	heapify_top_bottom(h,0);
	printf("Popped: %d\n", pop_value);
}


//Print Heap
void print_heap(heap* h){
	if(h->iterator<0){
		printf("Heap Empty...Nothing to print :( \n");
		return;
	}
	int i=0;
	for(;i<=h->iterator;i++){
		printf("%d\t",h->arr[i]);
	}
	printf("\n");
}

int main(void){
	heap* h=init_heap();
	
	int i=10;
	for(;i>4;i--){
		insert(h,i);
	}
	
	print_heap(h);
	
	pop_min(h);
	pop_min(h);
	pop_min(h);
	print_heap(h);
	pop_min(h);
	pop_min(h);pop_min(h);
	print_heap(h);
	
	free(h->arr);
	h->arr=NULL;
	free(h);
	h=NULL;
	
	return 0;
}


