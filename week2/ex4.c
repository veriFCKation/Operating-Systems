#include <stdio.h>

char str[255];

int count(char c){
	int i = 0, rez = 0;
	while (i < 256 && str[i] != '\n'){
		if (str[i] == c || (str[i] - 'a' == c - 'A' || str[i] - 'A' == c - 'a')){
			rez++;
		}
		i++;
	}
	return rez;
}

void countAll(){
	if (str[0] <= 90)
		printf("%c:%d", (str[0] + 32), count(str[0]));
	else
		printf("%c:%d", str[0], count(str[0]));
	int i = 1;
	while (i < 256 && str[i] != '\n'){
		if (str[i] <= 90)
			printf(", %c:%d", (str[i] + 32), count(str[i]));
		else
			printf(", %c:%d", str[i], count(str[i]));
		i++;
	}
	printf("\n");
}

int main(void){

fgets(str, 255, stdin);
countAll();

return 0;
}
