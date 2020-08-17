/*******************************
735. Asteroid Collision

We are given an array asteroids of integers representing asteroids in a row.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

Example 1:
Input: 
asteroids = [5, 10, -5] Output: [5, 10]
Explanation: 
The 10 and -5 collide resulting in 10.  The 5 and 10 never collide.

Example 2:
Input: 
asteroids = [8, -8] Output: []
Explanation: 
The 8 and -8 collide exploding each other.

Example 3:
Input: 
asteroids = [10, 2, -5] Output: [10]
Explanation: 
The 2 and -5 collide resulting in -5.  The 10 and -5 collide resulting in 10.

Example 4:
Input: 
asteroids = [-2, -1, 1, 2] Output: [-2, -1, 1, 2]
Explanation: 
The -2 and -1 are moving left, while the 1 and 2 are moving right.
Asteroids moving the same direction never meet, so no asteroids will meet each other.
Note:

The length of asteroids will be at most 10000.
Each asteroid will be a non-zero integer in the range [-1000, 1000].
*******************************/
//a=asteroids; aS=asteroidsSize; rS=returnSize

int* asteroidCollision(int* a, int aS, int* rS){
    //Init Stack
    int *stack=(int*)calloc(aS,sizeof(int));
    int top=-1;
    int size=0;
    
    //to track if any asteroid has been destroyed
    bool destroyed=0;
    while(!destroyed){
        for(int i=0;i<aS;i++){
            if(top==-1){
                stack[++top]=a[i];
                size++;
            } else{
                if(stack[top]>0){
                    if(a[i]<0){
                        if(abs(stack[top]) < abs(a[i])){
                            stack[top]=a[i];
                        } else if(abs(stack[top]) == abs(a[i])){
                            top--;size--;
                        }
                        destroyed=1;
                        continue;
                    }
                    stack[++top]=a[i]; size++;    
                    }   else{
                        stack[++top]=a[i]; size++;
                    }
                }
        }
        //if no asteroids destroyed, return
        if(!destroyed) {
            *rS=size;
            return stack;
        }
        
        //if stack empty, return
        if(top<0) {
            *rS=0;
            return NULL;
        }
        
        //copy current stack into input array and repeat the process till no asteroid destruction detected
        a=(int*)realloc(a,size*sizeof(int));
        memcpy(a,stack,size*sizeof(int));
        
        //reset stack parameters
        aS=size;
        top=-1;
        size=0;
        destroyed=0;
    }

    return stack;
    
}
