#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(){

int integer_var = INT_MAX; 
unsigned short unsign_short_var = USHRT_MAX;
long int long_var = LONG_MAX;
float float_var = FLT_MAX;
double double_var = DBL_MAX;

printf("%lu %d\n", sizeof(int), integer_var);
printf("%lu %d\n", sizeof(unsigned short), unsign_short_var);
printf("%lu %ld\n", sizeof(long int), long_var);
printf("%lu %f\n", sizeof(float), float_var);
printf("%lu %f\n", sizeof(double), double_var);


return 0;
}
