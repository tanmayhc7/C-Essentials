/***************
75. Sort Colors (Dutch National Flag)

Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Follow up:

Could you solve this problem without using the library's sort function?
Could you come up with a one-pass algorithm using only O(1) constant space?
 

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]
Example 3:

Input: nums = [0]
Output: [0]
Example 4:

Input: nums = [1]
Output: [1]
 

Constraints:

n == nums.length
1 <= n <= 300
nums[i] is 0, 1, or 2.
***************/

/************************
		ALGO
Maintain 3 pointers-> low , mid , high => low & mid start at 0; high from the end
if arr[mid]=0 => swap mid & left; increment both
if arr[mid]=1 => increment mid
if arr[mid]=2 => swap mid & high; decrement high
repeat until mid < high
***************************/

void swap(int *i,int *j){
    if(*i == *j) 
        return; 
    (*i)=(*i)^(*j);
    (*j)=(*i)^(*j);
    (*i)=(*i)^(*j);
}

void sortColors(int* nums, int ns){
    if(ns==1) return;
    
    int low =0, mid=0,high=ns-1;
    
    while(mid<=high){
        if(nums[mid]==0){
            swap(&nums[low],&nums[mid]);
            low++;
            mid++;
        } else if(nums[mid]==1){
            mid++;
        } else{
            swap(&nums[high],&nums[mid]);
            high--;
        }
    }
    
}

