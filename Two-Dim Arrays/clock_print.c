/*****************************
Leetcode #54:
Given a matrix of m x n elements (m rows, n columns), 
return all elements of the matrix in spiral order.
******************************/


#include <stdio.h>
#include <stdlib.h>

/******************************
     Time Complexity: O(m*n)
******************************/
#define rows 4
#define col 4

int* clockwise_print(int m[rows][col], int* ret_arr){ 
	int start_row=0; int end_row=rows-1; int start_col=0;int end_col=col-1;
	int ret_i=0;
	for(;ret_i<(rows*col);){
		for(int i=start_col;i<=end_col;i++){
			ret_arr[ret_i++]=m[start_row][i];	
		}
		start_row++;
		for(int i=start_row;i<=end_row;i++){
			ret_arr[ret_i++]=m[i][end_col];	
		}
		end_col--;
		for(int i=end_col;i>=start_col;i--){
			ret_arr[ret_i++]=m[end_row][i];		
		}
		end_row--;
		for(int i=end_row;i>=start_row;i--){
			ret_arr[ret_i++]=m[i][start_col];	
		}
		start_col++;

	}
}

void print_2d(int m[rows][col]){
	for(int j=0;j<rows;j++){
		for(int i=0;i<col;i++)
		{
			printf("%d ", m[j][i]);
		}	
		printf("\n");
	}
	printf("\n");
}

void print_ret_arr(int *arr){
	for(int i=0;i<rows*col;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int main(void){
	
	int a[rows][col] = { {1,2,3,4}, 
                    	     {12,13,14,5}, 
		             {11,16,15,6},
			     {10,9,8,7} }; 
	print_2d(a);
	int* ret_arr=(int*)malloc(rows*col*sizeof(int));
    	clockwise_print(a,ret_arr); 
	print_ret_arr(ret_arr);
	free(ret_arr);
	return 0;
}

