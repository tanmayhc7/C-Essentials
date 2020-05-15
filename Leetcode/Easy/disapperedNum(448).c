/***********************************************************************************

448. Find All Numbers Disappeared in an Array
Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]

Solution:
The idea is when visiting a number nums[i], flip the number at index i - 1 to negative. If the number at index i - 1 is already negative, then i is the number that occurs more than once.
Run a second loop and add the index of the positive values.
Time complexity: O(n)
Space Complexity: O(1) - Not considering the space required to return the result.
****************************************************************************************/
int* findDisappearedNumbers(int* nums, int n, int* returnSize){
        int j=0;
    int index=0;
    int* ret_arr=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        index=abs((abs(nums[i])-1));
        if(nums[index]>0){
            nums[index]*=-1;
        }
    }    
    for(int i=0;i<n;i++){
        if(nums[i]>0) ret_arr[j++]=i+1;
    }
    *returnSize=j;
    return ret_arr;
}
