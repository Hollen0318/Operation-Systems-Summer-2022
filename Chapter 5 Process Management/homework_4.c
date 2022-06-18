#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

int main() {
	int rc = fork();
	
	if (rc == 0) {
		
		printf("child process:\n");
		char * const argv[] = {"ls", NULL};
		char * const envp[] = {NULL};
		
//		Rules
//		Functions having l in their name need argument seperated by commas.
//		Function having v in their name need arguments as (v -> vector (array))
		
//		execl("/bin/ls", "ls", NULL);
//		execv("/bin/ls", argv);
		
//		1. execl and execv are nearly identical (have very little difference). They can execute commands given absolute path.

//		execlp("ls", "ls", NULL);
//		execvp("ls", argv);
		
//		2. execlp and execvp are nearly identical. They can execute commands included within the PATH enviornment given the command name.

//		execle("/bin/ls", "ls", NULL, envp);
//		execvpe("ls", argv, envp); 
		
//		3. execle and execvpe are nearly identical. They can execute commands within specific enviornments.
		
	} else if (rc > 0) {
		wait(NULL);
	} else {
		fprintf(stderr, "Error occured during fork()");
	}
}