/**************************************************
56. Merge Intervals

Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input. 

Example 1:
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

Example 2:
Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 

Constraints:

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104
***************************************************/
int cmpfunc(int** a, int** b)
{
    return (*a)[0] - (*b)[0];
}

int** merge(int** mat, int row, int* col, int* ret_row, int** ret_col){
    
     
    if((mat==NULL) || (row==0))
    {
        *ret_row = 0;
        return NULL;
    }
    
    qsort(mat, row,sizeof(int*),cmpfunc);
    int* temp=NULL;
    int k=0;
    temp=mat[0];
    for(int i=1;i<row;i++){
        if(temp[1] >= mat[i][0]){
            temp[1] = (temp[1] > mat[i][1])? temp[1] : mat[i][1];
        } else{
            mat[k][0]=temp[0];
            mat[k++][1]=temp[1];
            temp=mat[i];
        }
    }
    mat[k][0]=temp[0];
    mat[k++][1]=temp[1];
    
    
    *ret_row = k;
    (*ret_col) = (int*)malloc(k*sizeof(int));
    for(int i=0;i<k;i++)
    {
        (*ret_col)[i] = 2;
    }
    
    return mat;
}
