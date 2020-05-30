/*****************************************

34. Find First and Last Position of Element in Sorted Array
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
****************************************/
int leftMost(int* nums, int cap, int target) {
  int lo = 0;
  int hi = cap;
  while(lo < hi) {
    int mid = lo + (hi - lo) / 2;
    if(nums[mid] == target) hi = mid;
    else lo = mid + 1;
  }
  return lo;
}

int rightMost(int* nums, int numsSize, int cap, int target) {
  int lo = cap - 1;
  int hi = numsSize - 1;
  while(lo < hi) {
    int mid = hi - (hi - lo) / 2;
    if(nums[mid] == target) lo = mid;
    else hi = mid - 1;
  }
  return hi;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
  int* res = calloc(2, sizeof(int));
  res[0] = -1, res[1] = -1;
  *returnSize = 2;
  int l = 0, r = numsSize;
  while(l < r) {
    int mid = l + (r - l) / 2;
    if(nums[mid] > target) r = mid;
    else if(nums[mid] < target) l = mid + 1;
    else {
      res[0] = leftMost(nums, mid, target);
      res[1] = rightMost(nums, numsSize, mid, target);
      return res;
    }
  }
  return res;
}
