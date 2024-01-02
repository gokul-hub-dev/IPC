#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void signal_caught(int);
int main()
{
	int ret;
	ret = signal(SIGINT,signal_caught);
	if(ret == SIG_ERR)
	{
		printf("signal not registered\n");
		exit(0);
	}
	printf("calling rasise function\n");
	ret = raise(SIGINT);
	if(ret != 0)
	{
		printf("raise failed\n");
		exit(0);
	}
	printf("exiting...\n");
	return(0);
}
void signal_caught(int signal)
{
	printf("signal caught\n");
}
