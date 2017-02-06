#include<sys/types.h>
#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>


typedef struct value
	{
		char name[10];
		int hall;
		int emp_id;
		char branch[10];	
	}value;
	
void *th_f(void * th)   // this is fixed signature
{

value *v_p;
v_p=(value *)th;

printf("process id %lu\n", getpid());
printf("thread id %lu is executing \n", pthread_self());
printf(" Name -->%s \n",v_p->name);
printf(" Hall -->%d \n",v_p->hall);
printf(" Id -->%d \n",v_p->emp_id);
printf(" Branch -->%s \n",v_p->branch);


}

int main()
{

pthread_t tid;
int ret;
value *v1,*v2;
v1=(value *)malloc(sizeof(value));
v2=(value *)malloc(sizeof(value));
strcpy(v1->name,"taj");
v1->hall=2;
v1->emp_id=1;
strcpy(v1->branch,"IT");
strcpy(v2->name,"alam");
v2->hall=2;
v2->emp_id=2;
strcpy(v2->branch,"CS");


ret=pthread_create(&tid,NULL,th_f,(void *)v1);

if(ret!=0)
	{
		perror("thread 1 creation failed \n");
		exit(1);
	}
ret=pthread_create(&tid,NULL,th_f,(void *)v2);

if(ret!=0)
	{
		perror("thread 1 creation failed \n");
		exit(1);
	}

pthread_exit(NULL);
return 0;

}
