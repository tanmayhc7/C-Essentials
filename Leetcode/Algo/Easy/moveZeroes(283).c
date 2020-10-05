/*
 * Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
 */
void moveZeroes(int* nums, int N)
{
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
