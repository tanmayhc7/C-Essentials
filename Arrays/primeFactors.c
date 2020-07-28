#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int* prime_list=NULL;
int size=0;

bool is_prime(int num){
	int i=2;
	while(i < sqrt(num)){
		if(num%i == 0) return 0;
		i++;
		
	}
	return 1;
}

void create_prime_list(int num){
	prime_list=(int*)malloc((num/2)*sizeof(int));
	int j=0;
	int i;
	for(i=2;i<=num/2;i++){
		if(is_prime(i)){
			prime_list[j++]=i;
		}
	}
	size=j;
}

int* ret_arr=NULL;
int ret_size;
void prime_factors(int num){
	create_prime_list(num);
	int j=0;
	int k=0;
	ret_arr=(int*)malloc((size/2)*sizeof(int));
	while (num>1){
		while( num % prime_list[j] == 0){ 
			num /= prime_list[j];
			ret_arr[k++]=prime_list[j];
		}
		j++;
	}
	ret_size=k;
}

int main(void){
	
	int n=997*15;
	
	if(is_prime(n)){
		printf("%d ",n);
	}	else{
		prime_factors(n);
		int i;
		for(i=0;i<ret_size;i++){
			printf("%d ",ret_arr[i]);
		}
		free(prime_list);
		free(ret_arr);	
	}	

	
	return 0;
}
