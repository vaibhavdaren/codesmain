#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
int ret;
pid_t pid;

int choice;

printf("1: part a of question\n");
printf("2: part b of question\n");
printf("3: part c of question\n");
printf("4: part d of question\n");

scanf("%d",&choice);
switch(choice)
{

case 1: 
		pid=fork();

		if(pid==0)
			{
				printf(" In Child \n");
				ret=execlp("./pgm1","pgm1","2","3",(char*)0);
				if(ret<0)
					{
						perror("exec failed \n");
						exit(1);
					}
			}
		else
			{
				printf(" In parent \n");
			}
		break;
case 2:
		ret=execlp("./pgm1","pgm1","2","3",(char*)0);
		if(ret<0)
			{
				perror("exec failed \n");
				exit(1);
			}
		pid=fork();

		if(pid==0)
			{
				printf(" In Child \n");
			}
		else
			{
				printf(" In parent \n");
			}
		break;
case 3:
		pid=fork();

		ret=execlp("./pgm1","pgm1","2","3",(char*)0);
		
		if(pid==0)
			{
				printf(" In Child \n");
			}
		else
			{
				printf(" In parent \n");
			}
		break;
case 4:
		pid=fork();

		if(pid==0)
			{
				printf(" In Child \n");
			}
		else
			{
				printf(" In parent \n");
				ret=execlp("./pgm1","pgm1","2","3",(char*)0);
				if(ret<0)
					{
						perror("exec failed \n");
						exit(1);
					}
			}
		break;
}

return 0;
}
