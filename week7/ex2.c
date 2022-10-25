#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

int n;
scanf("%d", &n);
int *array = malloc(sizeof(int)  * n);
for (int i = 0; i < n; ++i){
	*(array+i) = i;
}
for (int i = 0; i < n; ++i){
	printf("%d ", *(array+i));
}
printf("\n");
free(array);
	
return 0;
}
