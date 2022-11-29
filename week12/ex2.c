#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<linux/input.h>

int main(){
char* path = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
int kbp = open(path, O_RDONLY);
int numb_of_events = 0;
while (numb_of_events < 30){
	struct input_event ie;
	ssize_t buf = read(kbp, &ie, sizeof(struct input_event));
	if (ie.type == 1){
		if (ie.value == 1){
			printf("PRESSED %x (%d))\n", ie.code, ie.code);
			fflush(stdout);
			numb_of_events++;
		}
		if (ie.value == 0){
			printf("RELEASED %x (%d))\n", ie.code, ie.code);
			fflush(stdout);
			numb_of_events++;
		}
	}
}

return 0;
}
