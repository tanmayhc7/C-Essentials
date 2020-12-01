/*************************************************************
46. Permutations

Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:
Input: nums = [0,1]
Output: [[0,1],[1,0]]

Example 3:
Input: nums = [1]
Output: [[1]]

Constraints:

1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.
***************************************************************/

// Get the number of permutations required using the factorial function => nPn = n! 
// Allocate Memory to return array accordingly

int factorial(int n){
    if(n==1) return 1;
    return n*factorial(n-1);
}

void swap(int* a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void helper(int** ret,int* count,int* nums,int size,int l,int h){
    if(l==h){
        for(int i=0;i<size;i++){
            ret[(*count)][i]=nums[i];
        }
        (*count)++;
    } else{
        for(int i=l;i<=h;i++){
          swap(&nums[l],&nums[i]);
          helper(ret,count,nums,size,l+1,h);
          swap(&nums[l],&nums[i]);
        }
    }
}

int** permute(int* nums, int size, int* row, int** col){
    *row=factorial(size);
    int** ret=(int**)malloc((*row)*sizeof(int*));
    for(int i=0;i<(*row);i++){
        ret[i]=(int*)malloc(size*sizeof(int));
    }
    *col=(int*)malloc(sizeof(int)*(*row));
    for(int i=0;i<(*row);i++)
    {
        (*col)[i]=size;
    }
    
    int count=0;
    helper(ret,&count,nums,size,0,size-1);    
    return ret;
}
