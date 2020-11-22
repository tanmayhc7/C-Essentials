/********************************************************
81. Search in Rotated Sorted Array II

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).

You are given a target value to search. If found in the array return true, otherwise return false.

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
Follow up:

This is a follow up problem to Search in Rotated Sorted Array, where nums may contain duplicates.
Would this affect the run-time complexity? How and why?
********************************************************/

/********************************************************
						ALGO
	Just eliminate the repating elements on both ends and 
	apply same logic as for Rotated array 1
********************************************************/

bool search(int* nums, int size, int target){
    int low=0,high=size-1;
        
    while(low <= high){
        while(low < high && nums[low]==nums[low+1]){
            low++;
        }
        while(low < high && nums[high]==nums[high-1]){
            high--;
        }
        
        int mid=low+(high-low)/2;
        
        if( (nums[mid]==target) || (nums[low]==target) || (nums[high]==target)) return 1;
        
        if(nums[low]<=nums[mid]){
            if( (target>nums[low]) && (target < nums[mid])){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }else{
            if( (target<=nums[high]) && (target > nums[mid])){
                low=mid+1;
            } else{
                high=mid-1;
            }            
        }   
    }
    return 0;
}
