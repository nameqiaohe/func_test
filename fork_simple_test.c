/*####################################################
# File Name: fork_simple_test.c
# Author: xxx
# Email: xxx@126.com
# Create Time: 2017-05-24 22:56:11
# Last Modified: 2017-05-24 23:16:08
####################################################*/
#include <stdio.h>
#include <unistd.h>

int glob = 10;
char buf[] = "write to stdout\n";

int main(int argc, char *argv[]){
	int var;
	pid_t pid;
	var = 90;

	if(write(STDOUT_FILENO, buf, sizeof(buf)-1) != sizeof(buf)-1){
		perror("write error");
	}
		
	printf("before fork()\n");

	pid = fork();
	if(pid < 0){
		perror("fork error");
	}else if(pid == 0){
		glob++;
		var++;
	}else{
		sleep(3);
	}

	printf("pid = %d, glob = %d, var  = %d\n", getpid(), glob, var);

	return 0;
}
