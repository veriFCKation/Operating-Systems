#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int args, char *argv[]){ //int n){
int fd;
char *path = "/tmp/ex1";
mkfifo(path, 0777);
fd = open(path, O_WRONLY);
char str[1024] = "\n";
write(fd, str, 1024);
close(fd);

while(1){
	fgets(str, 1024, stdin);
	fd = open(path, O_WRONLY);
	//for (i = 0; i < n; ++i)
	write(fd, str, 1024);
	close(fd);	
}
	
return 0;
}
