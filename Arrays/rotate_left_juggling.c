/*****************
Instead of moving one by one, divide the array in different sets
where number of sets is equal to GCD of n and d and move the elements within sets.
If GCD is 1 as is for the above example array (n = 7 and d =2), then elements will be moved within one set only, we just start with temp = arr[0] and keep moving arr[I+d] to arr[I] and finally store temp at the right place.

Here is an example for n =12 and d = 3. GCD is 3 and

Let arr[] be {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}

a) Elements are first moved in first set 
          arr[] after this step --> {4 2 3 7 5 6 10 8 9 1 11 12}

b)    Then in second set.
          arr[] after this step --> {4 5 3 7 8 6 10 11 9 1 2 12}

c)    Finally in third set.
          arr[] after this step --> {4 5 6 7 8 9 10 11 12 1 2 3}
*******************/

#include <stdio.h>

int get_gcd(int a,int b){
	if(!b) return a;
	else return get_gcd(b,a%b);
}

void rotate_left(int* arr,int size,int d){
	if(d>=size) d=d%size;
	if(!d) return;
	int gcd=get_gcd(size,d);
	printf("GCD: %d\n",gcd);
	int j,k,temp;
	int i=0;
	for(;i<gcd;i++){
		j=i;
		temp=arr[j];
		
		while(1){
			k=j+d;
			
			if(k>=size) k-=size;
			
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
	
	rotate_left(arr,size,6);
	print_arr(arr,size);
	
	return 0;
}
