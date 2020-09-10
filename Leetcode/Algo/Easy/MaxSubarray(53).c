/******************************************
53. Maximum Subarray

Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

Example 1:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

Example 2:
Input: nums = [1]
Output: 1

Example 3:
Input: nums = [0]
Output: 0

Example 4:
Input: nums = [-1]
Output: -1

Example 5:
Input: nums = [-2147483647]
Output: -2147483647

Constraints:

1 <= nums.length <= 2 * 104
-231 <= nums[i] <= 231 - 1
**********************************************************/

/**********************************************
	Method 1: Dynamic Programming 
Compute the sum at each i from 0 to i, if sum at i > arr[i], update sum to be sum+arr[i] else, 
SINCE A SINGLE ELEMENT CAN ALSO BE A SUBARRAY,if sum at i < arr[i], update sum to arr[i].
*************************************************/

int maxSubArray(int* nums, int ns){
    int sum=nums[0];
    int ret_max=nums[0];
    for(int i=1;i<ns;i++){
        sum=(nums[i]+sum) > nums[i] ? nums[i]+sum : nums[i];
        if(sum>ret_max) ret_max=sum;
    }     
    return ret_max;
}
