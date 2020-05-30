/*
 * Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
 */
void moveZeroes(int* nums, int N)
{
    /*
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N-1;j++)
        {
            if(nums[j]==0)
            {
                int temp=nums[j+1];
                nums[j+1]=nums[j];
                nums[j]=temp;
            }
        }
    }
    */
        int totalZeros = 0;

    for(int i = 0; i < N; i++) {
        if(nums[i] == 0) {
            totalZeros++;
        }
        else {
            nums[i - totalZeros] = nums[i];
        }
    }

    for(int i = (N - totalZeros); i < N; i++) {
        nums[i] = 0;
    }
}
