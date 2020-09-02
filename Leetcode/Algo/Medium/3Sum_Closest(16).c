/**************************
16. 3Sum Closest

Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. 
Return the sum of the three integers. You may assume that each input would have exactly one solution.

 

Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 

Constraints:

3 <= nums.length <= 10^3
-10^3 <= nums[i] <= 10^3
-10^4 <= target <= 10^4
***************************/
int threeSumClosest(int* nums, int ns, int target){
    quickSort(nums, 0,ns-1);
    int left,right;
    int min_diff=INT_MAX;
    int res;
    int sum,diff;
    for(int i=0;i<ns-2;i++){
        left=i+1; right=ns-1;
        while(left<right){
            sum=nums[i]+nums[left]+nums[right];
            diff=abs(sum-target);
            if(diff==0) return sum;
            if(diff<=min_diff) {
                min_diff=diff;
                res=sum;
            }
            if(sum < target){
                left++;
            } else if(sum > target){
                right--;
            }
        }
    }
    return res;
}
