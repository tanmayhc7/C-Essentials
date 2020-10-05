#include <stdio.h>

int get_gcd(int a,int b){
	if(!b) return a;
	else return get_gcd(b,a%b);
}

void rotate_right(int* arr,int size,int d){
	if(d>=size) d=d%size;
	int gcd=get_gcd(size,d);
	int j,k,temp;
	int i=size-1;
	for(;i>(size-gcd-1);i--){
		j=i;
		temp=arr[j];
		
		while(1){
			k=j-d;
			
			if(k<0) k+=size;
			
			if(k==i) break;
			
			arr[j]=arr[k];
			j=k; 
		}
		arr[j]=temp;
	}
}

void print_arr(int* arr,int size){
	int i=0;
	for(;i<size;i++){
		printf("%d\t",arr[i]);
	}
	printf("\n");
}

int main(void){
	
	int arr[]={1,2,3,4,5,6,7,8};
	int size=sizeof(arr)/sizeof(arr[0]);
	
	rotate_right(arr,size,2);
	print_arr(arr,size);
	
	return 0;
}
