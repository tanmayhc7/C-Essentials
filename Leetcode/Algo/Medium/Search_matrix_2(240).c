/*********************************************
240. Search a 2D Matrix II

Write an efficient algorithm that searches for a target value in an m x n integer matrix. The matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
 

Example 1:
Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
Output: true

Example 2:
Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
Output: false

Constraints:

m == matrix.length
n == matrix[i].length
1 <= n, m <= 300
-109 <= matix[i][j] <= 109
All the integers in each row are sorted in ascending order.
All the integers in each column are sorted in ascending order.
-109 <= target <= 109
**********************************************/
//Approach 1: Finalize the row first by checking if target lies in that row
bool searchRow(int** mat, int row, int col, int t){
    int left=0, right= col-1;
    
    int mid;
    while(left<=right){
        if(mat[row][left]==t || mat[row][right]==t){
            return 1;
        }

        mid=left+(right-left)/2;

        if(mat[row][mid]==t) return 1;
        
        if(mat[row][mid]>t){
            right=mid-1;
        } else{
            left=mid+1;
        }
    }
    return 0;
}

bool searchMatrix(int** mat, int row, int* col, int t){    
    for(int i=0;i<row;i++){
        if(mat[i][0]<=t && mat[i][(*col)-1]>=t){
            if(searchRow(mat,i,*col,t)){
                return 1;
            }
        }
    }   
    return 0;
}

//Approach 2: Narrow down on the position of the target
bool searchMatrix(int** matrix, int rSize, int* cSize, int target){
    int r=rSize-1, c=0;
    while(r>-1 && c < *cSize)
    {
        if(matrix[r][c] < target) c++;
        else if(matrix[r][c] > target) r--;
        else return true;
    }
    return false;
}
