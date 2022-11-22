#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

int main(){
DIR *dirp;
struct dirent *dp;

dirp = opendir("/");
if (dirp == NULL){
	printf("error\n");
	return 0;
}
printf("Content of the root directory:\n");
while((dp = readdir(dirp))  != NULL){
	printf("%s\n", dp->d_name);
}

}
