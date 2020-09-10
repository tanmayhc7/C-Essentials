/*******************************************
232. Implement Queue using Stacks

Implement the following operations of a queue using stacks.

push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.
Example:

MyQueue queue = new MyQueue();

queue.push(1);
queue.push(2);  
queue.peek();  // returns 1
queue.pop();   // returns 1
queue.empty(); // returns false
Notes:

You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).
****************************************************/
typedef struct {
    int* arr;
    int front,rear,size,capacity;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
    MyQueue* obj=(MyQueue*)malloc(sizeof(MyQueue));
    obj->size=0;
    obj->capacity=100;
    obj->arr=(int*)malloc((obj->capacity)*sizeof(int));
    obj->front=-1;
    obj->rear=-1;
    
    return obj;    
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    if(obj->size >= obj->capacity){
        return;
    }  
    obj->arr[++(obj->rear)]=x;
    if((obj->front)<0){
        obj->front++;
    }
    obj->size++;
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    if(obj->size<=0){
        return -1;
    }
    
    if(obj->size==1){
        obj->rear=-1;
        (obj->size)--;
        int x=obj->arr[(obj->front)];
        obj->front=-1;
        return x;        
    }
    --(obj->size);
    
    return obj->arr[(obj->front)++];
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    return obj->arr[(obj->front)];
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
  return !(obj->size > 0);
}

void myQueueFree(MyQueue* obj) {
    free(obj->arr);
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/
