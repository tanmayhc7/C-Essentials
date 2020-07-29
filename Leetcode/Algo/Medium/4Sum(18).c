/*************************************
	18. 4Sum
Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:

The solution set must not contain duplicate quadruplets.

Example:

Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
***********************************/

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

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){
     quick_sort(nums,0,numsSize-1);
    
    int a,b,k,buf[1000000][4],size=0,temp=0,c=0,p=0,sum=0;
    
    for(a=0;a < numsSize-3;a++)
    {
        for(b=a+1;b < numsSize-2;b++)
        {   
            int left = b+1; 
            int right = numsSize-1; 


            while(left < right)
            {
                sum=nums[a] + nums[b] + nums[left] + nums[right];
                if(sum == target){
                    if(size==0){
                        buf[size][0]=nums[a];
                        buf[size][1]=nums[b];
                        buf[size][2]=nums[left];
                        buf[size][3]=nums[right];
                        ++size;
                    } else {
                        c=0;
                        //check for duplicates
                        for(p=size-1;p>=0;p--)
                        {
                            if(buf[p][0]==nums[a] && buf[p][1]==nums[b] && buf[p][2]==nums[left] && buf[p][3]==nums[right])
                            {
                                ++c;
                                break;
                            }
                        }
                        //no duplicate found
                        if(c==0)
                        {
                            buf[size][0]=nums[a];
                            buf[size][1]=nums[b];
                            buf[size][2]=nums[left];
                            buf[size][3]=nums[right];
                            ++size;    
                        }
                    }
                   left++;
                   right--;
                } else if(sum > target)
                        right--;    
                  else if(sum < target)
                        left++;  
            }   
        }
    }
    
    
    *returnSize =size;
    int **result = (int **)malloc(size * sizeof(int *));
    *returnColumnSizes = (int *)malloc(size * sizeof(int));
    
    for (int i = 0; i <size; i++){
        (*returnColumnSizes)[i] =4;
        
        result[i] =(int *)malloc(4*sizeof(int));
        result[i][0] = buf[i][0];
        result[i][1] = buf[i][1];
        result[i][2] = buf[i][2];
        result[i][3] = buf[i][3];
    }   
    return result;    
}
