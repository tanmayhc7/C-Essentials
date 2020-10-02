#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int* arr;
	int top;
	int size;
}my_heap;

my_heap* init_heap(int size){
	my_heap* h=(my_heap*)malloc(sizeof(my_heap));
	h->arr=(int*)malloc(size*sizeof(int));
	h->top=-1;
	h->size=size;
	return h;
}

void print_arr(int* arr,int size){
	int i=0;
	for(;i<size;i++){
		printf("%d\t",arr[i]);
	}
	printf("\n");
}

void heapify_bottom_top(my_heap* h,int index){
	int parent=(index-1)/2;
	
	if( (index>=0) && (h->arr[index] < h->arr[parent]) ){
		int temp=h->arr[index];
		h->arr[index]=h->arr[parent];
		h->arr[parent]=temp;
		
		heapify_bottom_top(h,parent);
	}
}


void insert(my_heap* h,int val){
	h->arr[++(h->top)]=val;
	heapify_bottom_top(h,h->top);
}

void heapify_top_bottom(my_heap* h,int parent){
	int left=(2*parent)+1;
	int right=(2*parent)+2;
	int min=parent;
	int temp;
	if(left<=h->top && h->arr[left] < h->arr[parent]){
		min=left;
	}
	if(right<=h->top && h->arr[right] < h->arr[min]){
		min=right;
	}
	if(min!=parent){
		int temp=h->arr[min];
		h->arr[min]=h->arr[parent];
		h->arr[parent]=temp;
		
		heapify_top_bottom(h,min);
	}
}

int pop(my_heap* h){
	int pop=h->arr[0];
	h->arr[0]=h->arr[(h->top)--];
	heapify_top_bottom(h,0);
	return pop;
}

int main(void){
	
	int ip[]={1,4,5,2,3,7,8,6,10,9};
	int k=2;
	int size=sizeof(ip)/sizeof(ip[0]);
	printf("Ip Array:\t");
	print_arr(ip,size);

	my_heap* h=init_heap(k+1);
	int i=0;
	for(;i<=k;i++)
	{
		insert(h,ip[i]);
	}
	
	int j=0;
	for(i=k+1;i<size;i++){
		printf("Heap: \t");
		print_arr(h->arr,h->size);
		ip[j++]=pop(h);
		insert(h,ip[i]);
	}
	
	while(h->top>=0){
		ip[j++]=pop(h);
	}

	printf("Op Array:\t");
	print_arr(ip,size);
	
	
	return 0;
}
