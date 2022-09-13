#include <stdio.h>
#include <string.h>

int main(void){

char s[255];
fgets(s, 255, stdin);
int ind = 0;

while (ind < 256&& s[ind] != '.' && s[ind] != '\n'){
	ind++;
}

for (int i = ind - 1; i >= 0; --i){
	printf("%c", s[i]);
}
printf("\n");

return 0;
}

