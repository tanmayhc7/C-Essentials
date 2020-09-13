/*********************
152. Maximum Product Subarray

Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
**********************/

/*********
Track the current max and min values as there are both +ve and -ve values.
Step 1: if current num is +ve, check product with cur_max, update cur_max if necessary
Step 2: if current num is -ve, check product with cur_min, update cur_min if necessary
Step 3: check if cur_max>return value, update return value if necessary
Step 4: update prev_min and prev_max values
**************/

int get_MinMax(int a,int b,int c,bool flag){
    //1=Max 0=Min
    if(flag){
      return a > b? (a > c? a: c): (b > c? b: c);      
    } 
    return a < b? (a < c? a: c): (b < c? b: c);        
}


int maxProduct(int* nums, int ns){
    int cur_max=nums[0];
    int cur_min=nums[0];
    int prev_max=nums[0];
    int prev_min=nums[0];
    int ret_max=nums[0];
    for(int i=1;i<ns;i++){
        cur_max=get_MinMax(prev_max*nums[i],prev_min*nums[i],nums[i],1);
        cur_min=get_MinMax(prev_max*nums[i],prev_min*nums[i],nums[i],0);
        
        ret_max=get_MinMax(ret_max,cur_max,INT_MIN,1);
        
        prev_max=cur_max;
        prev_min=cur_min;
    }     
    return ret_max;
}
