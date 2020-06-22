/*****************************************************
	766. Toeplitz Matrix

A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same element.

Now given an M x N matrix, return True if and only if the matrix is Toeplitz.
 

Example 1:

Input:
matrix = [
  [1,2,3,4],
  [5,1,2,3],
  [9,5,1,2]
]
Output: True
Explanation:
In the above grid, the diagonals are:
"[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]".
In each diagonal all elements are the same, so the answer is True.
Example 2:

Input:
matrix = [
  [1,2],
  [2,2]
]
Output: False
Explanation:
The diagonal "[1, 2]" has different elements.

Note:

matrix will be a 2D array of integers.
matrix will have a number of rows and columns in range [1, 20].
matrix[i][j] will be integers in range [0, 99].

Follow up:

What if the matrix is stored on disk, and the memory is limited such that you can only load at most one row of the matrix into the memory at once?
What if the matrix is so large that you can only load up a partial row into the memory at once?

*****************************************************/

bool isToeplitzMatrix(int** matrix, int matrixRowSize, int* matrixColSize){
    int current_Row__sum=0;
    int next_Row__sum=0;
    
    int rows=matrixRowSize; int cols=*matrixColSize;
    bool return_val=1;

    for(int i=0;i<rows;i++){
        current_Row__sum=0;
        next_Row__sum=0;
        for(int j=0;j<cols-1;j++){
            current_Row__sum+=matrix[i][j];
        }
        
        if((i+1) < rows){
            for(int j=1;j<cols;j++){
                next_Row__sum+=matrix[i+1][j];
            }
            return_val=(current_Row__sum == next_Row__sum);
            if(!return_val) break;
        }
        else{
            break;
        }
    }
    
    return return_val;
}
