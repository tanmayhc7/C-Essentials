/******************************

155. Min Stack

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.

******************************/

//Time: O(1) Space:O(n) for min array

typedef struct {
    int *arr;
    int count;
    int *mins;
    int minCount;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack* top=(MinStack*)malloc(sizeof(MinStack));
    top->arr=(int*)malloc(sizeof(int)*100000);
    top->mins = (int*)malloc(sizeof(int)*100000);
    top->count=0;
    top->minCount=0;
    return top;
}

void minStackPush(MinStack* stack, int x) {
   stack->arr[stack->count++] = x;
    if(stack->minCount==0 || x <= stack->mins[stack->minCount-1])
        stack->mins[stack->minCount++] = x;
}

void minStackPop(MinStack* stack) {
    int top = stack->arr[stack->count-1];
    if(stack->mins[stack->minCount-1] == top)
        stack->minCount--;
    stack->count--;
}

int minStackTop(MinStack* stack) {
  return stack->arr[stack->count-1];
}

int minStackGetMin(MinStack* stack) {
  return stack->mins[stack->minCount-1];
}

void minStackFree(MinStack* stack) {
     free(stack->arr);
    free(stack->mins);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
