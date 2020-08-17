/************************************
867. Transpose Matrix

Given a matrix A, return the transpose of A.

The transpose of a matrix is the matrix flipped over it's main diagonal, switching the row and column indices of the matrix.

Example 1:

Input: [[1,2,3],[4,5,6],[7,8,9]]
Output: [[1,4,7],[2,5,8],[3,6,9]]

Example 2:

Input: [[1,2,3],[4,5,6]]
Output: [[1,4],[2,5],[3,6]]

Note:

1 <= A.length <= 1000
1 <= A[0].length <= 1000
**********************************/

int** transpose(int** A, int ASize, int* AColSize, int* returnSize, int** returnColumnSizes){
    
    //for input matrix
    int r=ASize; 
    int c=*AColSize;
    
    //Output matrix
    int **arr = (int **)calloc(c,sizeof(int *)); 
    *returnColumnSizes = malloc(sizeof(int)* c); //For keeping track of no of cols for each row
    for (int i=0; i<c; i++){
        arr[i] = (int *)calloc(r,sizeof(int)); 
        (*returnColumnSizes)[i] = r;
    }
    *returnSize=c;
    
    for(int i=0;i<c;i++){
        for(int j=0;j<r;j++){
            arr[i][j]=A[j][i];
        }   
    }
    return arr;
  
}
