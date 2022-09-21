#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stringSize(const char* s){
	int i = 0;
	while (s[i] != '\0') {++i; }
	return i;
};

struct Directory;

struct File{
	char* name[64];
	char* data;
	long int id;
	int size;
	struct Directory * parent;
};

struct Directory{
	struct File* files[64];
	struct Directory* directories[64];
	int num_files, num_directories;
	char* path[2048];
};

void pwd_file(struct File* file){
	printf("%s", *(file->parent->path));
	printf("/%s\n", *(file->name));
};

void add_to_file(struct File* file, const char* str){
	file->data = str;
	file->size = stringSize(str);
};

void append_to_file(struct File* file, const char* str){
	file->size = file->size + stringSize(str);
	//file->data = file->data + str;
	char rez[1024];
	int i = 0, j = 0;
	while (file->data[i] != '\0') {
		rez[i] = file->data[i];
		i++;
	}
	while (str[j] != '\0') {
		rez[i+j] = str[j];
		j++;
	}
	file->data = rez;
};

void add_file(struct File* file, struct Directory* directory){
	directory->files[directory->num_files] = file;
	directory->num_files++;
};

int main(void){

long int cur_id = 0;

struct Directory bin = {
	//.files = [],
	//.directories = [],
	.num_files = 0,
	.num_directories = 0,
	.path = "/bin"
};

struct Directory home = {
	//.files = [],
	//.directories = [],
	.num_files = 0,
	.num_directories = 0,
	.path = "/home"
};

struct Directory root = {
	//.files = [],
	.directories = {&bin, &home},
	.num_files = 0,
	.num_directories = 2,
	.path = "/"
};



struct File bash = {
	.name = "bash",
	.data = "",
	.id = ++cur_id,
	.size = 0,
	.parent = &bin
};
add_file(&bash, &bin);

struct File ex31 = {
	.name = "ex3_1.c",
	.data = "int printf(const char * format, ...);",
	.id = ++cur_id,
	.size = 37,
	.parent = &home
};
struct File ex32 = {
	.name = "ex3_2.c",
	.data = "//This is a comment in C language",
	.id = ++cur_id,
	.size = 33,
	.parent = &home
};
add_file(&ex31, &home);
add_file(&ex32, &home);


add_to_file(&bash, "Bourne Again Shell!!");
append_to_file(&ex31, "int main(){printf('Hello World!')}");

pwd_file(&bash);
pwd_file(&ex31);
pwd_file(&ex32);

return 0;
}
