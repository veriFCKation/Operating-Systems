#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main(int agrc, char *argv[]){
	int fd;
	int time = argv[1][0] - '0';
	char *path = "/tmp/ex1";
	mkfifo(path, 0777);
	char str[1024] = "###";
	fd = open(path, O_WRONLY);
	write(fd, str, 1024);
	close(fd);

	while(1){
		fd = open(path, O_WRONLY);
		fgets(str, 1024, stdin);
		for (int i = 0; i < 4; ++i)
			write(fd, str, 1024);
		close(fd);	
	}
	
return 0;
}
