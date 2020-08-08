/************************************
	581. Shortest Unsorted Continuous Subarray
Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, 
then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
Note:
Then length of the input array is in range [1, 10,000].
The input array may contain duplicates, so ascending order here means <=.
***********************************/
int findUnsortedSubarray(int* s, int n){
    if(n<2)return 0;
    int i,l,max,r=0,signal=1;
    for(i=1,l=0,max=s[0];i<n;i++){
        if(s[i]>=max){
            if(signal)l++;
            max=s[i];
        }
        else{
            signal=0;
            for(;l>=0&&s[i]<s[l];l--);
            r=i;
        }
    }
    return r-l>0?r-l:0;
}
