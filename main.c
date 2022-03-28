// #include <signal.h>
#include <unistd.h>
#include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #include <sys/types.h>
#include <sys/wait.h>
int main(int argc, char const *argv[])
{
	// printf("%s\n", argv[1]);
	int id = 0;
	if(argc > 1)
	{
		for (size_t i = 0; argv[1][i] != '\0'; i++)
		{
			id *= 10;
			id += (int)(argv[1][i] - '0');
		}
		
	}
	printf("I am %d pogram\n", id);
	id++;
	int pid = fork();
	if (pid == 0)
	{
		int length = snprintf( NULL, 0, "%d", id);
		char* str = malloc( length + 1 );
		snprintf(str, length + 1, "%d", id);
		char *args[3] = {"./main", str, NULL};
        execvp(args[0], args);
		free(str);
	}
	else
	{
		// wait(NULL);
		// printf("My child is dead\n");
	}
	return 0;
}