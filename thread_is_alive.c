/*####################################################
# File Name: thread_is_alive.c
# Author: xxx
# Email: xxx@126.com
# Create Time: 2017-06-03 12:48:37
# Last Modified: 2017-06-03 13:12:49
####################################################*/
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <errno.h>

void *func(){
	pthread_detach(pthread_self());

	int count = 0;

	while(count < 5){
		sleep(1);
		count++;
		printf("--- child thread ---");
	}
}

int main(int argc, char *argv[]){
	int rc;
	pthread_t tid;
	int flag = 0;

	while(1){
		if(flag == 0){
			rc = pthread_create(&tid, NULL, func, NULL);
			if(rc != 0){
			    printf("pthread_create() error\n");
				    exit(-1);
			}
			printf("main thread : first create thread\n");
			flag = 1;
		}

		rc = pthread_kill(tid, 0);
		if(rc == ESRCH){
			printf("the specified thread did not exists or already quit\n");
			printf("main thread : child is dead, new create child\n");

			rc = pthread_create(&tid, NULL, func, NULL);
			if(rc != 0){
				printf("main thread : pthread_create() error\n");
				exit(-1);
			}
		}else if(rc == EINVAL){
			printf("main thread : signal is invalid\n");
		}else{
			printf("main thread -- child is alive\n");
		}

		int count = 5;
		while(count){
			sleep(1);
			printf("main thread is runing\n");
			count--;
		}
	}

	return 0;
}
