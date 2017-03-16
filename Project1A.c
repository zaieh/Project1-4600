/*
Authors:	Zaira E Cruz , Luis Rangel
Description:	Project1A.c will create two child processes A1 and A2. These two process will be
		executed by a child process B1 inside Project1B.c. 
Title: 		CSCE 4600 Project#1
*/


#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>



int main ()
{
	pid_t pida1, pida2;
	int someint;

	pida1 = fork();
	printf(" pida1: %d\n", pida1);

	if(pida1 == 0)
	{
		//Inside process A1.
		printf("\nChild Process A1 inside Project1A.c\n");
		printf("A1 pid is %d\n", pida1);
		printf("Variable inside process A1: %d\n", someint);
	}
	else
	{
		pida2 = fork();

		if(pida2 > 0)
		{
			//Inside parent process.
			printf("\nParent Process inside ProjectA1.c.\n");
                        someint = 10;
			printf("Someint inside parent: %d\n",someint);


                        wait(0);
		}

		else
		{
			//Inside process A2.
			printf("\nProcess A2 inside Project1A.c\n");
                        printf("A2 pid is %d\n", pida2);
                        printf("\nVariable in process A2 from parent process: %d\n",someint);

		}
	}
	return 0;
}
