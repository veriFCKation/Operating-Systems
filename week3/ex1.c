#include <stdio.h>
#include <stdlib.h>

int main(void){

int foo(int age){
	return 2022 - age;
}

const int * q = 10;
int * p =(int *) malloc(sizeof(int) * 5);

int age;
for (int i = 0; i < 5; ++i){
	scanf("%d", &age);
	*(p+i) = age;
}
for (int i = 0; i < 5; ++i){
	*(p+i) = foo(*(p+i));
	printf("%d ", *(p+i));
}
free(p);

return 0;
}
