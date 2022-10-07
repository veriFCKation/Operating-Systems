#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Process{
	int arrT, bustT;
} Process;

int main(){
  int n, a, b;
  scanf("%d", &n);
  Process schedule[n];
  int tat, wt;
  double averTAT = 0, averWT = 0;
  for (int i = 0; i < n; ++i){
  	scanf("%d %d", &a, &b);
  	schedule[i].arrT = a;
  	schedule[i].bustT = b;
  }
  int currTime = schedule[0].arrT;
  for (int i = 0; i < n; ++i){
  	//in this case we haven't interruptions, so CT = WT
  	if (currTime < schedule[i].arrT) currTime = schedule[i].arrT;
  	wt = currTime - schedule[i].arrT;
  	tat = wt + schedule[i].bustT;
  	averTAT = averTAT + tat;
  	averWT = averWT + wt;
  	printf("Process %d (%d, %d):\n    CT  = %d\n    TAT = %d\n    WT  = %d\n", i, schedule[i].arrT, schedule[i].bustT, wt, tat, wt);
  	currTime = currTime + schedule[i].bustT;
  }
  averTAT = averTAT / n;
  averWT = averWT / n;
  printf("Average TAT = %f\nAverage WT  = %f\n", averTAT, averWT);

return 0;
}
