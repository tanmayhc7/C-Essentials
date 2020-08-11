/**************************************
565. Array Nesting
A zero-indexed array A of length N contains all integers from 0 to N-1. Find and return the longest length of set S, where S[i] = {A[i], A[A[i]], A[A[A[i]]], ... } subjected to the rule below.

Suppose the first element in S starts with the selection of element A[i] of index = i, the next element in S should be A[A[i]], and then A[A[A[i]]]… By that analogy, we stop adding right before a duplicate element occurs in S.

 

Example 1:

Input: A = [5,4,0,3,1,6,2]
Output: 4
Explanation: 
A[0] = 5, A[1] = 4, A[2] = 0, A[3] = 3, A[4] = 1, A[5] = 6, A[6] = 2.

One of the longest S[K]:
S[0] = {A[0], A[5], A[6], A[2]} = {5, 6, 2, 0}
 

Note:

N is an integer within the range [1, 20,000].
The elements of A are all distinct.
Each element of A is an integer within the range [0, N-1].
**************************************/

//Brute Force
//Time: O(n^2) Space: O(n)
int arrayNesting(int* nums, int size){
    int res=0;
    int i=0;
    int backup;
    int longest=0;
    int *nums_b=(int*)malloc(size*sizeof(int));
    memcpy(nums_b,nums,size*sizeof(int));
    for(int i=0;i<size;i++){
        while(nums[i]!=-1){
            res++;
            backup=nums[i];
            nums[i]=-1;
            i=backup;
        }
        if(res>longest) longest=res;
        memcpy(nums,nums_b,size*sizeof(int));
        res=0;
    }
    return longest;
}

//Using Visited Array 
//Using Bool array to track visited elements, for paths starting at visited elements return value will always be the same.
//Time: O(n) Space: O(n)
int arrayNesting(int* nums, int size){
    int res=0;
    int i=0;
    int backup;
    int longest=0;
    bool *nums_v=(bool*)calloc(size,sizeof(bool));
    for(int i=0;i<size;i++){
        while(nums_v[i]!=1){
            res++;
            nums_v[i]=1;
            i=nums[i];
        }
        if(res>longest) longest=res;
        res=0;
    }
    return longest;
}

//Without Using Extra Space
//set visited elements to MAX value 
//Time: O(n) Space: O(1)
int arrayNesting(int* nums, int size){
    int res=0;
    int i=0;
    int backup;
    int longest=0;
    for(int i=0;i<size;i++){
        while(nums[i]<size){
            res++;
            backup=nums[i];
            nums[i]=INT_MAX;
            i=backup;
        }
        if(res>longest) longest=res;
        res=0;
    }
    return longest;
}

