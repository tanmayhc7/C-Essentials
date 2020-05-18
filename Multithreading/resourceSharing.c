/*
 * resourceSharing.c
 *
 *  Created on: Dec 24, 2019
 *      Author: Tanmay
 */
// Let us create a global variable to change it in threads
int g = 0;

// The function to be executed by all threads
void* myThreadFun(void *vargp)
{
	int *myid = (int *)vargp;

	static int s = 0;

	int a=0;

	++s; ++g; ++a;

	printf("Thread ID: %d, Static: %d, Global: %d Local: %d\n", *myid, ++s, ++g, ++a);
}

int main()
{
	pthread_t tid;
	for (int i = 0; i < 3; i++)
		pthread_create(&tid, NULL, myThreadFun, (void *)&i);

	pthread_exit(NULL);
	return 0;
}




