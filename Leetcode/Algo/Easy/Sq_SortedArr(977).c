/*******************************************
977. Squares of a Sorted Array
Given an array of integers A sorted in non-decreasing order, return an array of the squares of each number, also in sorted non-decreasing order.

Example 1:

Input: [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Example 2:

Input: [-7,-3,2,3,11]
Output: [4,9,9,49,121]
 

Note:

1 <= A.length <= 10000
-10000 <= A[i] <= 10000
A is sorted in non-decreasing order.
*******************************************/
int* sortedSquares(int* A, int ASize, int* returnSize){
    int *res=(int*) malloc(ASize*sizeof(int));
    *returnSize=ASize;
    int left=0,right=ASize-1;
    int i=ASize-1;
    for(;left<=right;){

        if(abs(A[left])<abs(A[right]) && i>=0){
            res[i--]=A[right]*A[right];
            right--;
        }
        else if(abs(A[left])>abs(A[right]) && i>=0){
            res[i--]=A[left]*A[left]; left++;
        }
        else{
            res[i--]=A[left]*A[left];
            if(i>=0) res[i--]=A[left]*A[left];
            left++;right--;
        }
    }

    return res;
}

