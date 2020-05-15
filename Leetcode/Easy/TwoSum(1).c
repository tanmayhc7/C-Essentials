/*
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *result=(int*) malloc(2*sizeof(int));
    bool flag=0;
    *returnSize=2;
    for(int i=0;i<numsSize;i++)
    {
        for(int j=i+1;j<numsSize;j++)
        {
            if(nums[i]+nums[j]==target)
            {
                result[0]=i;
                result[1]=j;
                flag=1;
                break;
            }
        }
        if(flag==1) break;
    }
    return result;
}
