#include<stdio.h>
int main() {
	char *s; 
	char foo[] = "Hello Worl";
	s = foo;
	printf("s is %s\n", s);
	s[0] = foo[0];
	printf("s[0] is %c\n", s[0]);
	return(0);
}
