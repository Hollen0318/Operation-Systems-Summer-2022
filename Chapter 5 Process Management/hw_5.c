#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
	int rc = fork();
	if (rc == 0) {
		printf("I am child! (pid:%d)\n", getpid());
		printf("Child: The wait returns: %d\n",wait(NULL));
	} else if (rc > 0) {
		printf("The wait returns: %d\n",wait(NULL));
		printf("I am that dumbass's parent. (pid:%d)\n",getpid());
		printf("The wait returns: %d",wait(NULL));
	}
}