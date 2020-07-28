/**************************************************
	15. 3Sum
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
***************************************************/

//Genreral Solution: Sort first then start from the leftmost element,check with left and right pointers if sum is zero.

//Solution 1: Works for 313/315 testcases. Gives Memory Limit Exceeded for really large input array.


void sort(int* nums, int begin, int end)
{
    int l=begin, r=end;
    int v = nums[l+(r-l)/2];
    while(l <= r)
    {
        while(nums[l] < v) l++;
        while(nums[r] > v) r--;
        if(l <= r)
        {
            int t = nums[l];
            nums[l] = nums[r];
            nums[r] = t;
            l++; r--;
        }
    }
    if(r > begin)
        sort(nums, begin, r);
    if(l < end)
        sort(nums, l, end);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    if(!numsSize) {
        *returnSize=0;return NULL;
    }
    
    sort(nums,0,numsSize-1);
    int left=1;
    int right=numsSize-1;
    int** arr = (int**)malloc(sizeof(int*));
    *returnSize = 0;
    int sum;
    for(int i=0;i<numsSize-2;i++){
        while(i<numsSize-2 && i>0 && nums[i]==nums[i-1]) i++;
        int left=i+1;
        int right=numsSize-1;
        while(left < right){
            sum=nums[i]+nums[left]+nums[right];
            if(!(sum)){
                if(!*returnSize || (*returnSize && (nums[i]!=arr[*returnSize-1][0] ||
                                nums[left]!=arr[*returnSize-1][1]))){
                    *returnSize += 1;
                    arr = (int**)realloc(arr, sizeof(int*)*(*returnSize));
                    *returnColumnSizes = (int*)malloc(sizeof(int)*(*returnSize));
                    
                    for (int i = 0; i < (*returnSize); i++)
                         (*returnColumnSizes)[i] =3;

                    arr[*returnSize-1] = (int*)malloc(sizeof(int)*3);
                    arr[*returnSize-1][0] = nums[i];
                    arr[*returnSize-1][1] = nums[left];
                    arr[*returnSize-1][2] = nums[right];    
                }
                left++;
            }
            else if(sum < 0){
                left++;
            }
            else {
                right--;
            }
        }
    }
    
    return arr;    
}

//Solution 2: Uses a 2D array to store the triplets and then copy to the return array.

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){

    quick_sort(nums,0,numsSize-1);
    
    int i,j,k,b[1000000][3],t=0,x,y,temp=0,c=0,p=0;
    
    for(i=0;i<numsSize-2;i++)
    {
   
        j=i+1; //left
        k=numsSize-1; //right
        
    if(nums[i]>0 && nums[j]>0 && nums[k]>0)
    break;
        
        while(j<k)
        {
            if(nums[i]+nums[j]+nums[k]==0){
                if(t==0){
                    b[t][0]=nums[i];
                    b[t][1]=nums[j];
                    b[t][2]=nums[k];
                    ++t;
                } else {
                    c=0;
                    for(p=t-1;p>=0;p--)
                    {
                        if(b[p][0]==nums[i]&&b[p][1]==nums[j]&&b[p][2]==nums[k])
                        {
                            ++c;
                            break;
                        }
                    }
                    if(c==0)
                    {
                        b[t][0]=nums[i];
                        b[t][1]=nums[j];
                        b[t][2]=nums[k];
                        ++t;    
                    }
                }
               j++;
               k--;
            }
        
            else if(nums[i]+nums[j]+nums[k]>0)
            k--;    
            else if(nums[i]+nums[j]+nums[k]<0)
            j++;  
        }
        
    }
    
    
    *returnSize =t;
    int **result = (int **)malloc(t * sizeof(int *));
    *returnColumnSizes = (int *)malloc(t * sizeof(int));
    
    for (int i = 0; i <t; i++){
        (*returnColumnSizes)[i] =3;
        
        result[i] =(int *)malloc(3*sizeof(int));
        result[i][0] = b[i][0];
        result[i][1] = b[i][1];
        result[i][2] = b[i][2];
    }   
    return result;    
}

void quick_sort(int nums[],int f, int l) {
  int i, j, t, p = 0;

  if (f < l) {
    p = f;
    i = f;
    j = l;

    while (i < j) {
      while (nums[i] <= nums[p] && i < l)
        i++;
      while (nums[j] > nums[p])
        j--;
      if (i < j) {
        t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
      }
    }

    t = nums[p];
    nums[p] = nums[j];
    nums[j] = t;
    quick_sort(nums,f, j - 1);
    quick_sort(nums,j + 1, l);
  }
}
