/*****************************
350. Intersection of Two Arrays II

Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Note:

Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
Follow up:

What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
******************************/

int* intersect(int* n1, int n1S, int* n2, int n2S, int* rS) {
    quickSort(n1,0,n1S-1);
    quickSort(n2,0,n2S-1);
    
    int size=(n1S < n2S)? n1S : n2S;
    int* res=(int*)malloc(size*sizeof(int));
    int i=0,j=0,k=0;
    for(;i<n1S && j<n2S;){
        if(n1[i]<n2[j]){
            i++;
        } else if(n1[i] > n2[j]){
            j++;
        } else{
            res[k++]=n1[i];
            i++; j++;
        }
    }
    *rS=k;
    return res;
}
