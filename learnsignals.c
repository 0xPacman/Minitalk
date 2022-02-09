#include <stdio.h>
#include <signal.h>

void handle_sig(int sig)
{
	printf("sig: %d\n", sig);
}

int main()
{
	
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGINT, handle_sig);
	while (1);
}