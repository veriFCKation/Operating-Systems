#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main(){
char buf;
int num_of_proc = 0, num_of_res = 0, marked = 0;
int c[100][100], r[100][100];
int e[100], a[100];
bool p[100];

//read data
FILE *in;
in = fopen("input.txt", "r");
if (in == NULL){
	printf("Error");
}
fscanf(in, "%c", &buf);
while (buf != '\n'){
	e[num_of_res] = buf - '0';
	num_of_res++;
	fscanf(in, "%c", &buf);
	if (buf == '\n') {break;}
	fscanf(in, "%c", &buf);
}

for (int j = 0; j < num_of_res; ++j){
	fscanf(in, "%d", &a[j]);
}

fscanf(in, "%c", &buf);
fscanf(in, "%c", &buf);
fscanf(in, "%c", &buf);
while (buf != '\n'){
	fseek(in, -1, SEEK_CUR);
	for (int j = 0; j < num_of_res; ++j){
		fscanf(in, "%d", &c[num_of_proc][j]);
	}
	num_of_proc++;
	fscanf(in, "%c", &buf);
	fscanf(in, "%c", &buf);
}
for (int i = 0; i < num_of_proc; ++i){
	for (int j = 0; j < num_of_res; ++j){
		fscanf(in, "%d", &r[i][j]);
	}
}

//algorithm
for (int i = 0; i < num_of_proc; ++i)
	p[i] = false;
while (marked != num_of_proc){
	int indx = -1;
	for (int i = 0; i < num_of_proc; ++i){
		if (p[i]) {continue;}
		bool comp = true;
		for (int j = 0; j < num_of_res; ++j){
			if (r[i][j] > a[j]){
				comp = false;
				break;
			}
		}
		if (comp){
			indx = i;
			break;
		}
	}
	if (indx == -1) {break;}
	p[indx] = true;
	++marked;
	for (int j = 0; j < num_of_res; ++j){
		a[j] = a[j] + c[indx][j];
		
	}
}
if (marked == num_of_proc){
	printf("No deadlock is detected\n");
}
else{
	printf("Deadlock processes:  ");
	for (int i = 0; i < num_of_proc; ++i){
		if (!p[i]){
			printf("%d ", i);
		}
	}
	printf("\n");
}
fclose(in);

return 0;
}
