/********************************************

	59. Spiral Matrix II

Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

Example:

Input: 3
Output:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

***********************************************/	


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes){

    *returnSize=n;
    int **m = (int **)malloc(n * sizeof(int *));
    *returnColumnSizes=malloc(sizeof(int)*n);
    for(int i=0; i< n; i++)
    {
        *((*returnColumnSizes)+i)=n;
         m[i] = (int *)malloc(n * sizeof(int));
    }
    
    int start_row=0;   int end_row=n-1; 
    int start_col=0;   int end_col=n-1;

    int ret_i=1;

    while(ret_i<=(n*n)){
		for(int i=start_col;i<=end_col;i++){
			m[start_row][i]=ret_i++;	
		}
		start_row++;
        //if(ret_i==(rows*col)) break; //These stmts are required when R!=C (rectangular matrices)
		for(int i=start_row;i<=end_row;i++){
			m[i][end_col]=ret_i++;	
		}
		end_col--;
        //if(ret_i==(rows*col)) break;
		
        for(int i=end_col;i>=start_col;i--){
			m[end_row][i]=ret_i++;			
		}
		end_row--;
        //if(ret_i==(rows*col)) break;
		
        for(int i=end_row;i>=start_row;i--){
			m[i][start_col]=ret_i++;		
		}
		start_col++;
        //if(ret_i==(rows*col)) break;
	}
    return m;
    

}
