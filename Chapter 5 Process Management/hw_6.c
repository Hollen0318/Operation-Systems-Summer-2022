#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
	int rc = fork();
	if (rc == 0) {
		printf("Child: I am child! (pid:%d)\n", getpid());
		exit(0);
	} else if (rc > 0) {
		int status;
		waitpid(rc, &status, 0);
		printf("The status is %d\n",status);
		printf("Parent: I am that dumbass's parent. (pid:%d)\n",getpid());
	} else {
		fprintf(stderr, "Error occured during fork()");
	}
}