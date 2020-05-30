/*
 * Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.

Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2.  Elements that don't appear in arr2 should be placed at the end of arr1 in ascending order.
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize){
    int *arr3=(int*)malloc(arr1Size*sizeof(int));
    *returnSize=arr1Size;
    int map[1001]={0};
    int k=0;

    for(int i = 0; i< arr1Size;i++)
        map[arr1[i]]++;

    for(int i=0;i<arr2Size;i++)
    {
        for(int j=0;j<map[arr2[i]];j++)
        {
            arr3[k++]=arr2[i];
        }
        map[arr2[i]] = 0;
    }

    for(int j=0; j< 1001; j++)
    {
        //runs for #of different elements in arr1
       for(int i=0; i< map[j]; i++)
       {
           arr3[k++] = j;

       }
    }
    return arr3;
}
