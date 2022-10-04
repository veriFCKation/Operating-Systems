#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(void){
int fd;
char *path = "/tmp/ex1";
mkfifo(path, 0777);
char str[1024] = "";

while (1){
	fd = open(path, O_WRONLY);
	read(fd, str, 1024);
	close(fd);
	printf("-> %s", str);
	sleep(1);
}

return 0;
}
