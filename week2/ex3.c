#include <stdio.h>
#include <string.h>

void convert(char * num, int num_size, int from, int to){
	int indx = 0;
	long int pow = 1, num_from = 0;
	for (int i = num_size - 1; i >= 0; --i){
		if (num[i] - '0' > from){
			printf("cannot convert!\n");
			return;
		}
		num_from = num_from + pow*(num[i] - '0');
		pow = pow * from;
	}
	
	char num_to[255];
	while (num_from != 0){
		num_to[indx] = (num_from % to) + '0';
		indx++;
		num_from = num_from / to;
	}
	for (int i = indx - 1; i >= 0; --i)
		printf("%c", num_to[i]);
	printf("\n");
}

int main(void){

char str[255];
char inpt[255];
int s, t, sz = 0;

fgets(str, 255, stdin);
sscanf(str, "%s %d %d", &inpt, &s, &t);
while (sz < 256 && str[sz] != ' '){
	sz++;
}

convert(inpt, sz, s, t);

return 0;
}
