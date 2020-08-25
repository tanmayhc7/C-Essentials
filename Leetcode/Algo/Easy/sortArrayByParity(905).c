/**********************
	905. Sort Array By Parity

Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.

You may return any answer array that satisfies this condition.

Example 1:

Input: [3,1,2,4]
Output: [2,4,3,1]
The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.

Note:

1 <= A.length <= 5000
0 <= A[i] <= 5000
***********************/

int* sortArrayByParity(int* A, int ASize, int* returnSize){
int j=0;
int *result=(int*) malloc(ASize*sizeof(int));
*returnSize = ASize;
for(int i=0;i<ASize;i++)
  {
      if(A[i]%2==0 && j<ASize)
      {
          result[j]=A[i];
          j++;
      }
  }

for(int i=0;i<ASize;i++)
  {
      if(A[i]%2!=0 && j<ASize)
      {
          result[j]=A[i];
          j++;
      }
  }

return result;
}

Method 2:

void swap(int *A,int l,int r){
    int temp=A[l];
    A[l]=A[r];
    A[r]=temp;
}

int* sortArrayByParity(int* A, int ASize, int* returnSize){

    int* ret_Arr=(int*)calloc(ASize,sizeof(int));
    *returnSize=ASize;
    
    memcpy(ret_Arr,A,ASize*sizeof(int));
    int left=0, right=ASize-1;
    
    while(left<right){
        if(ret_Arr[left]%2 && !(ret_Arr[right]%2)){ // left = odd ; right = even
            swap(ret_Arr,left,right);
            left++;right--;
        } else if(!(ret_Arr[left]%2) && !(ret_Arr[right]%2)){ // left=even; right=even
            left++;
        } else if((ret_Arr[left]%2) && (ret_Arr[right]%2)){// left=odd right=odd         
            right--;
        }
        else{ // left=even right=odd
            right--;left++;
        }
    }
    

    return ret_Arr;
    

}

