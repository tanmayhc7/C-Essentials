/*****************************
Leetcode #59:Spiral Matrix II
Given a positive integer n, generate a square matrix filled with elements from 1 to n^2 in spiral order.
******************************/


#include <stdio.h>
#include <stdlib.h>

void clockwise_print_matrix(int n){ 
	int matrix[n][n];
	int start_row=0; int end_row=n-1; int start_col=0;int end_col=n-1;
	int ret_i=1;
	for(;ret_i<=(n*n);){
		for(int i=start_col;i<=end_col;i++){
			matrix[start_row][i]=ret_i++;	
		}
		start_row++;
		for(int i=start_row;i<=end_row;i++){
			matrix[i][end_col]=ret_i++;;	
		}
		end_col--;
		for(int i=end_col;i>=start_col;i--){
			matrix[end_row][i]=ret_i++;;		
		}
		end_row--;
		for(int i=end_row;i>=start_row;i--){
			matrix[i][start_col]=ret_i++;	
		}
		start_col++;
	}
	for(int j=0;j<n;j++){
		for(int i=0;i<n;i++)
		{
			printf("%d ", matrix[j][i]);
		}	
		printf("\n");
	}
	printf("\n");
}


int main(void){
	
    	clockwise_print_matrix(3); 
	return 0;
}

