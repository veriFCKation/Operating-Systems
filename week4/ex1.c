#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main(void){

clock_t t1 = clock();

pid_t id = getpid();
pid_t parent_id;

pid_t pid = fork();
clock_t t2 = clock();
wait(NULL);

if (pid == 0){
	id = getpid();
	parent_id = getppid();
	printf("Process2 ID = %d, parent ID = %d, time = %f\n", id, parent_id, 1000*((float)(clock()-t2))/CLOCKS_PER_SEC);
}
else{
	pid_t pid2 = fork();
	clock_t t3 = clock();
	wait(NULL);
	if (pid2 == 0){
		pid_t id3 = getpid();
		pid_t parent_id3 = getppid();
		printf("Process3 ID = %d, parent ID = %d, time = %f\n", id3, parent_id3, 1000*((float)(clock()-t3))/CLOCKS_PER_SEC);
	}
	else{
		parent_id = getppid();
		printf("Process1 ID = %d, parent ID = %d, time = %f\n", id, parent_id, 1000*((float)(clock()-t1))/CLOCKS_PER_SEC);
	}
}

return 0;
}
