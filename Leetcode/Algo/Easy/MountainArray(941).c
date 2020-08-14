/*************************************
941. Valid Mountain Array
Given an array A of integers, return true if and only if it is a valid mountain array.

Recall that A is a mountain array if and only if:

A.length >= 3
There exists some i with 0 < i < A.length - 1 such that:
A[0] < A[1] < ... A[i-1] < A[i]
A[i] > A[i+1] > ... > A[A.length - 1]

Example 1:

Input: [2,1]
Output: false
Example 2:

Input: [3,5,5]
Output: false
Example 3:

Input: [0,3,2,1]
Output: true
 

Note:

0 <= A.length <= 10000
0 <= A[i] <= 10000 
*************************************/
bool validMountainArray(int* A, int ASize){
    if(ASize<3) return false;
    int left=0, right=ASize-1;
    while(left<ASize-1 && (A[left]<A[left+1])){left++;}
    if(left==ASize-1) return false;
    while(right>0 && (A[right]<A[right-1])){right--;}
    if(right==0) return false;
    return left==right;
}
