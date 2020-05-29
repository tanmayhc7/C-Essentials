/********************************************
	989. Add to Array-Form of Integer
For a non-negative integer X, the array-form of X is an array of its digits in left to right order.  
For example, if X = 1231, then the array form is [1,2,3,1].
Given the array-form A of a non-negative integer X, return the array-form of the integer X+K.

Example 1:

Input: A = [1,2,0,0], K = 34
Output: [1,2,3,4]
Explanation: 1200 + 34 = 1234
Example 2:

Input: A = [2,7,4], K = 181
Output: [4,5,5]
Explanation: 274 + 181 = 455
Example 3:

Input: A = [2,1,5], K = 806
Output: [1,0,2,1]
Explanation: 215 + 806 = 1021
Example 4:

Input: A = [9,9,9,9,9,9,9,9,9,9], K = 1
Output: [1,0,0,0,0,0,0,0,0,0,0]
Explanation: 9999999999 + 1 = 10000000000

Note:

1 <= A.length <= 10000
0 <= A[i] <= 9
0 <= K <= 10000
If A.length > 1, then A[0] != 0
*********************************************/
int* addToArrayForm(int* A, int ASize, int k, int* returnSize){
    
    if(k==0){
        *returnSize=ASize;
        return A;
    }
    
    int carry=0; int sum=0;
    
    for(int i=ASize-1;i>=0;i--){
        sum=A[i]+(k%10)+carry;
        if(sum>=10)
        {
            carry=sum/10; sum=sum%10;
        }
        else{
            carry=0;
        }
        A[i]=sum;
        k/=10;
    }
    
    int extra_size=0;
    if(k>0){
        extra_size=log10(k)+1;
    }
    if(carry>0) extra_size++;
    
    if(extra_size>=0) *returnSize=ASize+extra_size;
    else *returnSize=ASize;
    
    int* ret_arr=(int*)malloc(*returnSize*sizeof(int));
    
    //Copy A into return array depending on extra_size
    if(extra_size>=0) memcpy(ret_arr+extra_size,A,ASize*sizeof(int));
    else memcpy(ret_arr,A,ASize*sizeof(int));
    
    if(extra_size>=0){
        for(int i=extra_size-1;i>=0;i--){
           sum=(k%10)+carry;
            if(sum>=10)
            {
                carry=sum/10; sum=sum%10;
            }
            else{
                carry=0;
            }
            ret_arr[i]=sum;
            k/=10;
        }
    }
    
    //cancel out leading zero
    if(ret_arr[0] != 0) return ret_arr;
    else{
        *returnSize=*returnSize-1;;
    }
    return ret_arr+1;    
}

