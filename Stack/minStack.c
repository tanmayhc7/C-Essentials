/**************************************
	Time: O(1) Space:O(1) for min array
	This implementation will only help retrieve minimum values in O(1) Space & Time
	Note: Stack does not contain exact values pushed in it.
***************************************/

#include <stdio.h>

typedef struct {
    int *arr;
    int top_idx;
    int min;
} MinStack;

MinStack* minStackCreate(void) {
    MinStack* stack=(MinStack*)malloc(sizeof(MinStack));
    stack->arr=(int*)malloc(sizeof(int)*10);
    stack->top_idx=-1;
    stack->min=32655;
    return stack;
}

void minStackPush(MinStack* stack, int x) {
	if(stack->top_idx<0){
		stack->arr[++stack->top_idx]=x;
		stack->min=x;
		return;
	}
	if(x < stack->min){
		stack->arr[++stack->top_idx]=2*x - stack->min;
		stack->min=x;
	}
	else
	{
		stack->arr[++stack->top_idx]=x;
	}
}

void minStackPop(MinStack* stack) {
	if(stack->top_idx<0){	return;	}
	if(stack->arr[stack->top_idx] < stack->min){
		stack->min= 2*stack->min - stack->arr[stack->top_idx--];
	}
}

int minStackTop(MinStack* stack) {
  return stack->arr[stack->top_idx];
}

int minStackGetMin(MinStack* stack) {
  return stack->min;
}

void minStackFree(MinStack* stack) {
    free(stack->arr);
}

int main(void){
	
	MinStack *stack=minStackCreate();
	minStackPush(stack,-15);
	minStackPush(stack,-12);
	minStackPush(stack,-20);
	minStackPush(stack,-100);
	printf("Min: %d \n", minStackGetMin(stack));
	minStackPop(stack);
	printf("Min: %d\n", minStackGetMin(stack));
	minStackPop(stack);
	printf("Min: %d\n", minStackGetMin(stack));
	
	
	return 0;
}


