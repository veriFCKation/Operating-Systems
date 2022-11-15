#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

int inum;

int filter(const struct dirent* entry){
	if (entry->d_ino == inum)
		printf("%s ", entry->d_name);
	return (entry->d_ino == inum) ? 1: 0;
}

int main(){
DIR *dirp;
struct dirent *dp;
struct stat fl;

dirp = opendir("tmp");
if (dirp == NULL){
	printf("error\n");
	return 0;
}
char *str1 = "tmp/";
printf("File --- Hard Links\n");
struct dirent **list = NULL;

while((dp = readdir(dirp))  != NULL){
	char* name = dp->d_name;
	char *path = malloc(strlen(str1) + strlen(name) + 1);
	strcpy(path, str1);
	strcat(path, name);
	stat(path, &fl);
	if (fl.st_nlink > 2){
		inum = fl.st_ino;
		printf("%s --- ", name);
		scandir("tmp", &list, filter, NULL);
		printf("\n");
	}
}

(void)closedir(dirp);
return 0;
}
