#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(void){

int fd[2];
pipe(fd);
char str[1024];
if (fork() == 0){
	while (1){
		read(fd[0], str, 1024);
		printf("> %s", str);
	}
}
else{
	while(1){
		fgets(str, 1024, stdin);
		write(fd[1], str, 1024);
	}
}

return 0;
}
