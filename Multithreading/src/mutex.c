/*
 * mutex.c
 *
 *  Created on: Dec 24, 2019
 *      Author: Tanmay
 */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *functionC(void);
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
int  counter = 0;

int main(void)
{
   int rc1, rc2;
   pthread_t thread1, thread2;

   /* Create independent threads each of which will execute functionC */
   rc1=pthread_create( &thread1, NULL, &functionC, NULL);
   if(rc1)
   {
      printf("Thread creation failed: %d\n", rc1);
   }
   rc2=pthread_create( &thread2, NULL, &functionC, NULL);
   if(rc2)
   {
      printf("Thread creation failed: %d\n", rc2);
   }

   /* Wait till threads are complete before main continues. Unless we  */
   /* wait we run the risk of executing an exit which will terminate   */
   /* the process and all threads before the threads have completed.   */

   pthread_join( thread1, NULL);
   pthread_join( thread2, NULL);

   exit(0);
}
/*
When a mutex lock is attempted against a mutex which is held by another thread, the thread is blocked until the mutex is unlocked.
When a thread terminates, the mutex does not unless explicitly unlocked.
Nothing happens by default.
*/
void *functionC(void* vargs)
{
   pthread_mutex_lock( &mutex1 );
   counter++;
   printf("Counter value: %d\n",counter);
   pthread_mutex_unlock( &mutex1 );
}
