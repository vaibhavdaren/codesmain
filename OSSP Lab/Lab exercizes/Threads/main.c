#include<sys/types.h>
#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

void *th_f(void *arg)   // this is fixed signature
{


printf("process id %lu\n", getpid());
printf("thread id %lu is executing \n", pthread_self());


}

int main()
{

pthread_t tid[5];
int ret;

ret=pthread_create(&tid[0],NULL,th_f,NULL);

if(ret!=0)
	{
		perror("thread 1 creation failed \n");
		exit(1);
	}
ret=pthread_create(&tid[1],NULL,th_f,NULL);

if(ret!=0)
	{
		perror("thread 2 creation failed \n");
		exit(1);
	}
ret=pthread_create(&tid[2],NULL,th_f,NULL);

if(ret!=0)
	{
		perror("thread 3 creation failed \n");
		exit(1);
	}
ret=pthread_create(&tid[3],NULL,th_f,NULL);

if(ret!=0)
	{
		perror("thread 4 creation failed \n");
		exit(1);
	}
ret=pthread_create(&tid[4],NULL,th_f,NULL);

if(ret!=0)
	{
		perror("thread 5 creation failed \n");
		exit(1);
	}
pthread_exit(NULL);
return 0;

}
