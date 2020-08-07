/*************************
231. Power of Two
Given an integer, write a function to determine if it is a power of two.

Example 1:

Input: 1
Output: true 
Explanation: 20 = 1
Example 2:

Input: 16
Output: true
Explanation: 24 = 16
Example 3:

Input: 218
Output: false	
**************************/

/********************
If a number is a power of 2, then the bit’s of the previous number will be a complement of the number.
*********************/

bool isPowerOfTwo(int num){
    if(num<0) return 0;
    return (num != 0) && ((num &(num - 1)) == 0);
}
