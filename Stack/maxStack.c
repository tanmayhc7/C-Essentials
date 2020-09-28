/****************************

MaxStack implementation in Constant Space & Time
Note: Stack does not store exact values that are pushed.
****************************/

#include <stdio.h>
#include <limits.h>

typedef struct{
	int *arr;
	int top;
	int max;
}maxStack;

maxStack* init_Stack(void){
	maxStack* ptr=(maxStack*)malloc(sizeof(maxStack));
	ptr->arr=(int*)malloc(10*sizeof(int));
	ptr->top=-1;
	ptr->max=INT_MIN;
	return ptr;
}

void push(maxStack *ptr, int x){
	if(ptr->top>=10){
		printf("Overflow\n");
		return;
	}
	if(ptr->top<0){
		ptr->arr[++(ptr->top)]=x;
		ptr->max=x;
		return;
	}
	if(x > ptr->max){
		ptr->arr[++(ptr->top)]=2*x-(ptr->max);
		ptr->max=x;
	} else{
		ptr->arr[++(ptr->top)]=x;
	}
}

int pop(maxStack* ptr){
	if(ptr->top<0){
		printf("Underflow\n");
		return;
	}
	if(ptr->arr[ptr->top] >= ptr->max){
		printf("Popped: %d\t",ptr->max);
		ptr->max= 2*ptr->max - ptr->arr[(ptr->top)--];
	} else{
		printf("Popped: %d\t",ptr->arr[(ptr->top)--]);
	}
}

int getMax(maxStack* ptr){
	return ptr->max;
}

int main(void){
	maxStack* ptr=init_Stack();
	
	push(ptr,3);	
	push(ptr,4);
	push(ptr,10);
	push(ptr,2);
	push(ptr,11);
	
	printf("Max: %d\n",getMax(ptr));
	
	pop(ptr); printf("Max: %d\n",getMax(ptr));
	pop(ptr); printf("Max: %d\n",getMax(ptr));
	pop(ptr); printf("Max: %d\n",getMax(ptr));
	pop(ptr); printf("Max: %d\n",getMax(ptr));
	pop(ptr); printf("Max: %d\n",getMax(ptr));
	pop(ptr); printf("Max: %d\n",getMax(ptr));
	
	return 0;
}
