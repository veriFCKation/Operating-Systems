#include <stdio.h>

int main(void){
char type;
int n, m;
printf("Choose pattrern type: 'c' - cascade; 'a' - arrow; 'r' - rectangle  => ");
while (1){
	scanf("%c", &type);
	if (type == '\n')
		continue;
	if (type == 'r'){
		printf("Print height => ");
		scanf("%d", &n);
		printf("Print width  => ");
		scanf("%d", &m);

		for (int i = 1; i <= n; ++i){
			for (int j = 1; j <= m; ++j){ printf("*");}
			printf("\n");
		}
		break;
	}
	if (type == 'c'){
		printf("Print height  => ");
		scanf("%d", &n);

		for (int i = 1; i <= n; ++i){
			for (int j = 1; j <= i; ++j){ printf("*");}
			printf("\n");
		}
		break;
	}
	if (type == 'a'){
		printf("Print width  => ");
		scanf("%d", &n);

		for (int i = 1; i <= n; ++i){
			for (int j = 1; j <= i; ++j){ printf("*");}
			printf("\n");
		}
		for (int i = n -1 ; i > 0; --i){
			for (int j = 1; j <= i; ++j){ printf("*");}
			printf("\n");
		}
		break;
	}
	printf("ERROR\n");
	printf("'c' - cascade; 'a' - arrow; 'r' - rectangle  \n");
}
return 0;
}
