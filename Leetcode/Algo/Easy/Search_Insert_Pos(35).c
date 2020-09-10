/*******************************
35. Search Insert Position

Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example 1:

Input: [1,3,5,6], 5
Output: 2
Example 2:

Input: [1,3,5,6], 2
Output: 1
Example 3:

Input: [1,3,5,6], 7
Output: 4
Example 4:

Input: [1,3,5,6], 0
Output: 0
*****************************/
//Binary Search
void helper(int* nums,int l,int h,int target, int* res){
    if(l<h){
        int mid=(l+h)/2;
        
        if(nums[mid] > target){
            helper(nums,l,mid,target,res);
        } else if(nums[mid] < target){
            helper(nums,mid+1,h,target,res);
        } else{
            *res=mid;
            return;
        }
    }
    else{
        (*res)=l;
        return;
    }
}


int searchInsert(int* nums, int ns, int target){
    if(nums[0] > target) return 0;
    if(nums[ns-1] < target) return ns;
    
    if(ns==1){
        if(target > *nums) return 1;
        return 0;
    }
    
    int ret=-1;
    helper(nums,0,ns-1,target,&ret);
    return ret;
    
}
