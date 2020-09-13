/*****************************
33. Search in Rotated Sorted Array

You are given an integer array nums sorted in ascending order, and an integer target.

Suppose that nums is rotated at some pivot unknown to you beforehand (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

If target is found in the array return its index, otherwise, return -1.

Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

Example 3:
Input: nums = [1], target = 0
Output: -1
 
Constraints:

1 <= nums.length <= 5000
-10^4 <= nums[i] <= 10^4
All values of nums are unique.
nums is guranteed to be rotated at some pivot.
-10^4 <= target <= 10^4
****************************/
//Iterative: Time:O(log n) | Space: O(1)

int binSearch(int* nums, int l, int h, int target){
    int mid;
    while(l<=h){
        mid=(l+h)/2;

        if(nums[mid]==target) return mid;

        if(nums[l]<=nums[mid]){
            if(target<nums[mid] && target>=nums[l]){
                //check left
                h=mid-1;
            } else{
                //check right
                l=mid+1;
            }
        } else{
            if(target>nums[mid] && target<=nums[h]){
                //check right
                l=mid+1;
            } else{
                //check left
                h=mid-1;
            }
        }
    }
    return -1;
}

int search(int* nums, int ns, int target){
    return binSearch(nums,0,ns-1,target);
}

//Recursive: Time:O(log n) | Space: stack space for recursive calls

int binSearch(int* nums, int l, int h, int target){
    if(l>h) return -1;
    
    int mid=(l+h)/2;
    
    if(nums[mid]==target) return mid;
    
    if(nums[l]<=nums[mid]){
        if(target<nums[mid] && target>=nums[l]){
            //check left
            return binSearch(nums,l,mid-1,target);
        } else{
            //check right
            return binSearch(nums,mid+1,h,target);
        }
    } else{
        if(target>nums[mid] && target<=nums[h]){
            //check right
            return binSearch(nums,mid+1,h,target);
        } else{
            //check left
            return binSearch(nums,l,mid-1,target);
        }
    }   
}

int search(int* nums, int ns, int target){
    return binSearch(nums,0,ns-1,target);
}
