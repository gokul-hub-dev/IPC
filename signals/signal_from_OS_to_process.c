#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

static void
ctrlC_singal_handler(int sig)
{
	printf("Ctrl-C pressed \n");
	printf("Bye bye\n");
	exit(0);
}
static void 
abort_signal_handler(int sig)
{
	printf("process is aborted\n");
	printf("Bye Bye\n");
	exit(0);
}

int main(int argc , char **argv)
{
	signal(SIGINT,ctrlC_singal_handler);
	signal(SIGABRT,abort_signal_handler);
	char ch;
	printf("abort process (Y/N) \n");
	scanf("%c",&ch);
	if(ch == 'Y')
		abort();
	return 0;
}
