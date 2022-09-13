#include <stdio.h>

int main(void){
int n;
long int f2 = 1, f1 = 1, f0 = 0, ans;

scanf("%d", &n);

if (n < 3){
	if (n == 2)
		printf("1\n");
	else
		printf("%d\n", n);
	return 0;
}

for (int i = 3; i <= n; ++i){
	ans = f0 + f1 + f2;
	f0 = f1;
	f1 = f2;
	f2 = ans;
}
printf("%ld\n", ans);

return 0;
}
