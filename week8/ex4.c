#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

int main(){

size_t one_mb = 10*1024*1024;

for (int i = 0; i < 10; ++i){
	int *p;
	memset(p, 0, one_mb);
	int who = RUSAGE_SELF;
	struct rusage usage;
	int rez = getrusage(RUSAGE_SELF, &usage);
	printf("%d", rez);
	sleep(1);
}

return 0;
}
