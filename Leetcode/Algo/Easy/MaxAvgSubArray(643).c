/*******************************
	643. Maximum Average Subarray I
Given an array consisting of n integers, find the contiguous subarray of given length k that has the maximum average value. And you need to output the maximum average value.

Example 1:

Input: [1,12,-5,-6,50,3], k = 4
Output: 12.75
Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75
 

Note:

1 <= k <= n <= 30,000.
Elements of the given array will be in the range [-10,000, 10,000].
********************************/
double findMaxAverage(int* nums, int numsSize, int k){        
    int sum=0;
    int j=0;
    for(int m=0;m<k;m++)
        sum+=nums[j++];
    int max_sum=sum;

    for(int i=1;i<=numsSize-k;i++){
            
        sum-=nums[i-1];
        sum+=nums[i+k-1];

        if(sum>max_sum) max_sum=sum;
    }
    return (double)max_sum/(double)k;
}
