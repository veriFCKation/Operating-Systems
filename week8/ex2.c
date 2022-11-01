#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(){

size_t one_mb = 10*1024*1024;

for (int i = 0; i < 10; ++i){
	int *p;
	memset(p, 0, one_mb);
	sleep(1);
}
//ex2
///during execution of this program (10 sec) si and so fields becomes zeros
//ex3
///during execution of this progrem (10 sec) every second in the top of list (actually between first five positions) ont process appearss

return 0;
}
