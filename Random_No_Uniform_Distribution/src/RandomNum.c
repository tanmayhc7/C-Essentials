/*
 ============================================================================
 Name        : Random_No_Uniform_Distribution.c
 Author      : Tanmay
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


unsigned int coin_flip() {
  unsigned int x=rand();
  return (x%2);
}
/*
Using flip_coin result to reach a random number between 1 to N using Binary Search Algorithm(if returned is 0 we search from 1 to N/2, else from (N/2)+1 to N)
*/
unsigned int custom_random(unsigned int N){
    unsigned int start=1;
    unsigned int end=N;
    while(start<=end)
    {
     int r= coin_flip();
     int mid=(start+end)/2;

     if((end-start+1)%2!=0)
     {
        int rr=coin_flip();
        if(rr==1)
        mid = mid-1;
     }
     if(r==1)
     {
      end=mid;
     }
     else {
       start=mid+1;
     }
      if(start==end)
     {
       return start;
     }
    }
    return start;
}

int main()
{
  srand(time(NULL));
  unsigned int p[10];
  for(int i = 0; i<10; i++){
    p[i]=0;
  }
  //Using 20000 samples to get the distribution
  for (int i=0; i<20000; ++i) {
    p[custom_random(10)-1]++;
  }
  int sum=0;
  for(int i = 0; i<10; i++){
    printf("Counts[%d]: %d \n",i+1,p[i]);
    sum+=p[i];
  }
  printf("Sum: %d\n",sum);
  return 0;
}
