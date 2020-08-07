/***********************************************
	342. Power of Four
Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example 1:

Input: 16
Output: true
Example 2:

Input: 5
Output: false
Follow up: Could you solve it without loops/recursion?
************************************************/

/******************
A number n is a power of 4 if following conditions are met.
a) There is only one bit set in the binary representation of n (or n is a power of 2)
b) The bits don’t AND(&) any part of the pattern 0xAAAAAAAA
*******************/

bool isPowerOfFour(int n){
    if(n<0) return 0;
    return n != 0 && ((n&(n-1)) == 0) && !(n & 0xAAAAAAAA);
}
