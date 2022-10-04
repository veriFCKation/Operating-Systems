#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main(){
int fd;
char *path = "/tmp/ex1";
char last[1024] = "###";
char str[1024];

while (1){
	fd = open(path, O_WRONLY);
	read(fd, str, 1024);
	close(fd);
	if (strcmp(last, str)){
		printf("-> %s", str);
		strcpy(last, str);
	}
	sleep(1);
}

return 0;
}
