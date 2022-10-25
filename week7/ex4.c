#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* myRealloc(void *ptr, size_t size){
	if (ptr == NULL){
		ptr = malloc(size);
		return ptr;
	}
	if (size == 0){
		free(ptr);
		ptr = NULL;
		return ptr;
	}
	void* ptr2 = malloc(size);
	void **p = &ptr;
	void **q = &ptr2;
	while(*q != (ptr2+size)){
		*q = *p;
		++p;
		++q;
	}
	free(ptr);
	ptr = ptr2;
	free(ptr2);
	return ptr;
}

int main(){
int *ptr = malloc(sizeof(int)*5);
*(ptr+4) = 20;
ptr = myRealloc(ptr, sizeof(int)*10);
printf("%d ", *(ptr+4));

return 0;
}
