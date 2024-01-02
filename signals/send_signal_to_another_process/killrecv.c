#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void signal_handler(int signal){
	printf("signal caught....\n");
	exit(EXIT_FAILURE);
}
int main()
{
	signal(SIGUSR1,signal_handler);
	char ch;
	scanf("%c",&ch);
	return 0;
}
