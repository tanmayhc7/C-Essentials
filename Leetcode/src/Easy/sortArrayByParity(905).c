/*
 * Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.

You may return any answer array that satisfies this condition.
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
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
