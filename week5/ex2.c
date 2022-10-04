#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>


typedef struct Thread{
	int i;
	pthread_t id;
	char* message[256];
};
void *printMsg(void *thread_){
	struct Thread *thread = (struct Thread *) thread_;
	printf("%s %d\n", thread->message, thread->i);
	pthread_exit(NULL);
}

int main(){

struct Thread thr_arr[5];
for (int i = 0; i < 5; ++i){
	thr_arr[i].i = i;
	strcpy(thr_arr[i].message, "Hello from thread ");
	pthread_create(&thr_arr[i].id, NULL, printMsg, (void *)&thr_arr[i]);
	printf("Thread %d is created\n", i);
	pthread_join(thr_arr[i].id, NULL);
}

return 0;
}
