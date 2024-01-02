#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int main()
{
	char command[50];
	int pid;
	sprintf(command,"pidof killrecv");
	FILE* fb = popen(command,"r");
	fscanf(fb,"%d",&pid);
	printf("pidof killrecv : %d\n",pid);

	kill(pid,SIGUSR1);
	pclose(fb);
	return 0;
}
