/*
 * Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
 */
void swap(int* a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;    
}

void moveZeroes(int* nums, int numsSize){
    int l=0,r=1;
    
    while(r<numsSize){
        if(nums[l]==0 && nums[r]!=0){
            swap(&nums[l],&nums[r]);
            l++;r++;
        } else if((nums[l]!=0 && nums[r]!=0) || (nums[l]!=0 && nums[r]==0)){
            l++;r++;
        } else{
            r++;
        }   
    }   
}
