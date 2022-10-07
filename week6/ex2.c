#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Process{
	int arrT, bustT;
} Process;

//we alwaus need to choose the process with minimum bust time
//in this case we still haven't interruptions, so CT = WT
//priority queue can be more opltimal, but I don't think it's obligatory in this case 
//and it harder to implement (it's better to spend this time prepearing for midterm)

int main(){
  int n, a, b;
  scanf("%d", &n);
  Process schedule[n];
  Process buf;
  int tat, wt;
  double averTAT = 0, averWT = 0;
  for (int i = 0; i < n; ++i){
  	scanf("%d %d", &a, &b);
  	schedule[i].arrT = a;
  	schedule[i].bustT = b;
  }
  
  int currTime = schedule[0].arrT;
  for (int i = 0; i < n; ++i){
  	int k = 0, j = 0;
  	while (j < n && schedule[j].arrT != -1){
  		if (schedule[j].arrT < schedule[k].arrT || (schedule[j].arrT == schedule[k]. arrT && schedule[j].bustT < schedule[k].bustT)){
  			k = j;
  		}
  		++j;
  	}
  	if (currTime < schedule[k].arrT) currTime = schedule[k].arrT;
  	wt = currTime - schedule[k].arrT;
  	tat = wt + schedule[k].bustT;
  	averTAT = averTAT + tat;
  	averWT = averWT + wt;
  	printf("Process %d (%d, %d):\n    CT  = %d\n    TAT = %d\n    WT  = %d\n", i, schedule[k].arrT, schedule[k].bustT, wt, tat, wt);
  	currTime = currTime + schedule[k].bustT;
  	buf = schedule[k]; 
  	schedule[k] = schedule[n - i - 1];
  	schedule[n - i - 1] = buf;
  	schedule[n - i - 1].arrT = -1;
  }
  averTAT = averTAT / n;
  averWT = averWT / n;
  printf("Average TAT = %f\nAverage WT  = %f\n", averTAT, averWT);

return 0;
}
