/**************************************
	728. Self Dividing Numbers
A self-dividing number is a number that is divisible by every digit it contains.

For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.

Also, a self-dividing number is not allowed to contain the digit zero.

Given a lower and upper number bound, output a list of every possible self dividing number, including the bounds if possible.

Example 1:
Input: 
left = 1, right = 22
Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
Note:

The boundaries of each input argument are 1 <= left <= right <= 10000.
**************************************/
bool isSelfDividing(int n){
    int rem;
    int backup=n;
    while(n>1){
        rem=n%10;
        if(rem==0 || (backup%rem!=0)) return false;
        n/=10;
    }
    return true;
    
}

int* selfDividingNumbers(int left, int right, int* returnSize){
    int *ret=NULL;
    int size=0;
    while(left<10 && left<=right){
        if(!size) {
            size++;
            ret=(int*)malloc(size*sizeof(int));
            ret[0]=left;
            left++;
            continue;
        }
        size++;
        ret=(int*)realloc(ret,size*sizeof(int));
        ret[size-1]=left;
        left++;
    }
    
    for(;left<=right;left++){
        if(isSelfDividing(left)){
            size++;
            ret=(int*)realloc(ret,size*sizeof(int));
            ret[size-1]=left;
        }           
    }
    
    *returnSize=size;
    return ret;    
}
