#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void sig_handler(int signum)
{
	int i=5;
	int j=0;
	int k;
	switch (signum) {
		case SIGCHLD:
			printf("I am in SIGCHLD\n");
			fflush(stdout);
			// sleep(1);
			raise(SIGUSR1);
			break;
		case SIGUSR1: 
			printf("I am in SIGUSR1\n");
			fflush(stdout);
			raise(SIGUSR2);
			break;
		case SIGUSR2: 
			printf("I am in SIGUSR2\n");
			fflush(stdout);
			
			int id = getpid();
			kill(id, SIGINT);
			// exit(1);
			break;
		case SIGINT: 
			printf("I am in SIGINT\n");
			fflush(stdout);
			if (!(fork())) {
				int *a = 0;
				*a = 5;
			}
			
			break;
		case SIGSEGV:
			printf("I am in SIGSEGV\n");
			fflush(stdout);
			int id2 = getpid();
			if (!(fork())) {
				double a = 5/0;
			}
			exit(1);
			break;
		case SIGFPE:
			printf("I am in SIGFPE\n");
			fflush(stdout);
			exit(1);




		//לכאן לא נשלחים סיגנלים
		case SIGBUS:
			printf("I am in SIGBUS\n");
			fflush(stdout);
			exit(0);
			break;	
		case SIGCONT: 
			printf("I am in SIGCONT\n");
			fflush(stdout);
			k=i/j;
			printf("lalala\n");
			fflush(stdout);
			break;
		
	}
}

// void sig_handler2(int signum)
// {
// 	printf("I am in sighandler2222\n");
// 	fflush(stdout);
// 	exit(1);
// }

int main()
{
	int status;
	signal (SIGCHLD, sig_handler);
	signal (SIGUSR1, sig_handler);
	signal (SIGFPE, sig_handler);
	signal (SIGUSR2, sig_handler);
	signal (SIGSTOP, sig_handler);
	signal (SIGCONT, sig_handler);
	signal (SIGINT, sig_handler);
	signal (SIGSEGV, sig_handler);
	signal (SIGBUS, sig_handler);
	if (!(fork())) {
		exit(1);
	}
	wait(&status);

}

