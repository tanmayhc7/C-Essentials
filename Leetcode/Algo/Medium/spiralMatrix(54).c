/************************************************
54. Spiral Matrix
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*******************************************************/
int* spiralOrder(int** m, int matrixRowSize, int* matrixColSize, int* ret_size){
    if(matrixRowSize==0){
        *ret_size=0;
        return NULL;
    } 

    int col=*matrixColSize;
    int rows=matrixRowSize;

    int start_row=0;   int end_row=rows-1; 
    int start_col=0;   int end_col=col-1;

    *ret_size=rows*col;

    int* ret_arr=(int*)malloc((*ret_size)*sizeof(int));
	int ret_i=0;

    while(ret_i<(rows*col)){
		for(int i=start_col;i<=end_col;i++){
			ret_arr[ret_i++]=m[start_row][i];	
		}
		start_row++;
        if(ret_i==(rows*col)) break; //These stmts are required when R!=C (rectangular matrices)
		for(int i=start_row;i<=end_row;i++){
			ret_arr[ret_i++]=m[i][end_col];	
		}
		end_col--;
        if(ret_i==(rows*col)) break;
		for(int i=end_col;i>=start_col;i--){
			ret_arr[ret_i++]=m[end_row][i];		
		}
		end_row--;
        if(ret_i==(rows*col)) break;
		for(int i=end_row;i>=start_row;i--){
			ret_arr[ret_i++]=m[i][start_col];	
		}
		start_col++;
        if(ret_i==(rows*col)) break;
	}
    return ret_arr;
    
    
}
