/**************************
88. Merge Sorted Array

Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:

The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is equal to m + n) to hold additional elements from nums2.
Example:

Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]
 

Constraints:

-10^9 <= nums1[i], nums2[i] <= 10^9
nums1.length == m + n
nums2.length == n
*************************/

/*******
ALGO:
Start from the end, 
if arr B has element greater than arr A, fill the zero position with B[k]
else fill the zero position with the last known element of A

for cases where there are no positive nums in A(i.e. m=0)
copy all elements from B to A using the second loop. The first loop will not be entered.

**************/

void merge(int* n1, int n1S, int m, int* n2, int n2S, int n){

    int i=m-1, j=m+n-1, k=n-1;
    
    while(i>=0 && k>=0){
        if(n2[k] > n1[i]){
            n1[j--]=n2[k--];
        } else{
            n1[j--]=n1[i--];
        }   
    }
    while(k>=0){
        n1[j--]=n2[k--];
    }
    
}
