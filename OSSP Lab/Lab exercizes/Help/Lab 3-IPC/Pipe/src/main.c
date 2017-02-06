/* To Demonstrate how the pipe is used */

#include"header.h"
main (int argc, char *argv[])
{
	int    pipefd[2];
	int    lcounter = 0;
	size_t buffsize = 31;
	char   writebuffer[32];
	char   readbuffer[32];
	pid_t  pid, pid1;
	int    status;
	int    filewritefd, filereadfd;
	

	if(NULL ==argv[1])
		{
			printf(" Source file not given \n");
			exit(1);
		}
	if(NULL ==argv[2])
		{
			printf(" Dsetination file not given \n");
			exit(1);
		}
	pipe (pipefd);			/*Create Pipe with pipefd[0] as readend
					  and pipefd[1] as writeend*/
	pid = fork ();			/*Create the child*/
	
	if (0 == pid)			/*Child */
	{     
		printf(" In First Child \n"); 
		close(pipefd[0]);	/*Close the read end of the pipe */
		filereadfd = open (argv[1], O_RDONLY);
	
		while (buffsize!=0)
		{
			
			memset(writebuffer,'\0',buffsize);
			buffsize = read(filereadfd, writebuffer, MAX);
			if (buffsize > 0)
			{
				write(pipefd[1], writebuffer, buffsize);
			}
			
		}
	
		close(pipefd[1]);
		close(filereadfd);
		
	}
	else				/*Parent*/
	{
		pid1=fork();
		
		if(0==pid1)
			{
				close(pipefd[1]);	/*Close the write end of pipe*/
      		 		printf("Second Child\n");

				filewritefd = open (argv[2], O_CREAT|O_WRONLY|O_TRUNC,S_IRWXU);

				while (buffsize!=0)
					{
						buffsize = read(pipefd[0], readbuffer, buffsize);
					
						if (buffsize > 0)
							{
							write(filewritefd, readbuffer, buffsize);
				
							}
					}
	
				close(pipefd[0]);
				close(filewritefd);
			}
		else
			{
				printf(" In Parent \n");
				
			}
		return 0;
	}

}
