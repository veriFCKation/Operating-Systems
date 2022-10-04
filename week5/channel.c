#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main(){

int fd[2];
if(pipe(fd))
	return 0;
if (fork() == 0){
	char last[1024] = "###";
	char str[1024];
	while (1){
		read(fd[0], str, 1024);
		if (strcmp(str, last) != 0){
			printf("<< %s", str);
			strcpy(last, str);
		}
	}
}
else{
	char str[1024];
	while(1){
		fgets(str, 1024, stdin);
		write(fd[1], str, 1024);
	}
}

return 0;
}
