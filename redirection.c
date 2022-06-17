#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
//	printf("hello world (pid:%d)\n",(int) getpid());
	int rc = fork();
	if (rc < 0) {
//		fork failed
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if (rc == 0) {
//		child: redirect standard output to a file
		close(STDOUT_FILENO);
		open("./redirection.output", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
		
//		now exec "wc"...

		char *myargs[3];
		myargs[0] = strdup("wc");
		myargs[1] = strdup("redirection.c");
		myargs[2] = NULL;
		execvp(myargs[0], myargs);
	} else {
		int rc_wait = wait(NULL);
//		parent gose down this parth (main) 
//		printf("hello, I am parent of %d (rc_wait:%d) (pid:%d)\n", rc, rc_wait, (int) getpid());
	}
	return 0;
}