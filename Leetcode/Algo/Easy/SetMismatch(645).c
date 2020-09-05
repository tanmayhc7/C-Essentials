/***********************************
645. Set Mismatch

The set S originally contains numbers from 1 to n. But unfortunately, due to the data error, 
one of the numbers in the set got duplicated to another number in the set, which results in repetition of one number and loss of another number.

Given an array nums representing the data status of this set after the error. 
Your task is to firstly find the number occurs twice and then find the number that is missing. Return them in the form of an array.

Example 1:
Input: nums = [1,2,2,4]
Output: [2,3]
Note:
The given array size will in the range [2, 10000].
The given array's numbers won't have any order.
****************************************/
int* findErrorNums(int* nums, int nS, int* returnSize){
    int* arr=(int*)calloc(nS,sizeof(int));
    *returnSize=2;
    for(int i=0;i<nS;i++)
        arr[nums[i]-1]++;
    int* ret=(int*)malloc(2*sizeof(int)); 
    for(int i=0;i<nS;i++){
        if(arr[i]>1){
            ret[0]=i+1;
        }
        if(arr[i]==0){
            ret[1]=i+1;
        }
    }
    return ret;
}
