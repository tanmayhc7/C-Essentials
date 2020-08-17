/***********************
1299. Replace Elements with Greatest Element on Right Side
Given an array arr, replace every element in that array with the greatest element among the elements to its right, and replace the last element with -1.

After doing so, return the array.

 

Example 1:

Input: arr = [17,18,5,4,6,1]
Output: [18,6,6,6,1,-1]
 

Constraints:

1 <= arr.length <= 10^4
1 <= arr[i] <= 10^5
****************************/
int* replaceElements(int* arr, int arrSize, int* returnSize){
    int* ret=(int*)malloc(arrSize*sizeof(int));
    *returnSize=arrSize;
    ret[arrSize-1]=-1;
    int max=arr[arrSize-1];
    for(int i=arrSize-2;i>=0;i--){
        if(arr[i]>max){
            ret[i]=max;
            max=arr[i];
        } else{
            ret[i]=max;
        }
        
    }
    
    return ret;
}
