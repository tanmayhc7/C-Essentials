
/**************************************************
442. Find All Duplicates in an Array
Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?

Example:
Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]

Solution:
The idea is when visiting a number nums[i], flip the number at index i - 1 to negative. If the number at index i - 1 is already negative, then i is the number that occurs more than once.
Time complexity: O(n)
Space Complexity: O(1)
*****************************************************/
int* findDuplicates(int* nums, int n, int* returnSize){
    int j=0;
    int index=0;
    int* ret_arr=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        index=abs((abs(nums[i])-1));
        if(nums[index]>0){
            nums[index]*=-1;
        }
        else{
            ret_arr[j++]=abs(nums[i]);
        }
    }
    *returnSize=j;
    return ret_arr;
}
