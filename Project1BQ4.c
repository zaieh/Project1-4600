/*
Authors:	Zaira E Cruz and Luis Rangel
Description:	Project1B will create a child processes B1. This process will execute
		Project1A.
Title: 		CSCE 4600 Project#1
*/


#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	pid_t pid;
	pid = fork();//Making the fork call to create child process B1.
	char strcommand[] = "./Project1A";

	if(pid == 0)//Checking if pid is child process.
	{
		//Inside child process B1.
		sleep(10);//Luis Q4-Making the child last longer than the parent by putting the process to sleep
		printf("\nChild process B1 inside Project1B.c.\n");
		printf("B1 pid is %d.\n", pid);
		execlp(strcommand, strcommand, (char *)0);
	}
	else
	{
		//Inside parent process.
		printf("\nParent process inside Project1B.c\n");
		//wait(0);//Luis Q4-Commented this out so that the parent can terminate first
			}
	return 0;
}
