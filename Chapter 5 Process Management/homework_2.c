#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
	int x = 100;
	printf("hello world (pid:%d)\n",(int) getpid());
	int rc = fork();
	if (rc < 0) {
//		fork failed
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if (rc == 0) {
//		Child new process
		printf("hello, I am child (pid:%d)\n", (int) getpid());
		printf("the x value is:%d\n", x);
	} else {
		int rc_wait = wait(NULL);
//		parent gose down this parth (main) 
		printf("hello, I am parent of %d (rc_wait:%d) (pid:%d)\n", rc, rc_wait, (int) getpid());
		printf("the x value is:%d\n", x);
	}
	return 0;
}