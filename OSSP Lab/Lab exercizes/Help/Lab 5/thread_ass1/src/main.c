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
int i,ret;

ret=pthread_create(&tid[0],NULL,th_f,NULL);

if(ret!=0)
	{
		perror("thread 1 creation failed \n");
		exit(1);
	}
ret=pthread_create(&tid[1],NULL,th_f,NULL);

if(ret!=0)
	{
		perror("thread 1 creation failed \n");
		exit(1);
	}
ret=pthread_create(&tid[2],NULL,th_f,NULL);

if(ret!=0)
	{
		perror("thread 1 creation failed \n");
		exit(1);
	}
ret=pthread_create(&tid[3],NULL,th_f,NULL);

if(ret!=0)
	{
		perror("thread 1 creation failed \n");
		exit(1);
	}
ret=pthread_create(&tid[4],NULL,th_f,NULL);

if(ret!=0)
	{
		perror("thread 1 creation failed \n");
		exit(1);
	}
for(i=0;i<5;i++)
	pthread_join(tid[i], NULL);
pthread_exit(NULL);
return 0;

}
