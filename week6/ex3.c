#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Process{
	int arrT, bustT, ct, wt, tat, lastMeet;
} Process;

int main(){
  int n, quant, a, b;
  scanf("%d %d", &n, &quant);
  Process schedule[n];
  Process buf;
  int tat, wt;
  double averTAT = 0, averWT = 0;
  for (int i = 0; i < n; ++i){
  	scanf("%d %d", &a, &b);
  	schedule[i].arrT = a;
  	schedule[i].bustT = b;
  	schedule[i].tat = b;
  	schedule[i].ct = -1;
  	schedule[i].wt = 0;
  	schedule[i].lastMeet = a;
  }
  //sort schedule by arr time
  for (int i = 0; i < n; ++i){
  	for (int j = 0; j < n - i - 1; ++j){
  		if ((schedule[j].arrT > schedule[j+1].arrT) || ((schedule[j].arrT == schedule[j+1].arrT) && (schedule[j].bustT > schedule[j+1].bustT))){
  			buf =  schedule[j];
  			schedule[j] = schedule[j+1];
  			schedule[j+1] = buf;
  		}
  	}
  }
  
  
  int flag = 1;
  int currTime = 0;
  int k = 0;
  while (flag){ // it will work until we finish all processes
  	flag = 0;
  	int j = k;
  	while (j < n){ 
  		if (schedule[j].arrT != -1){
	  		k = j;
	  		flag = 1;
	  		break;
  		}
  		++j;
  	}
  	if (j == n){
  		j = 0;
  		while (j < k){
  			if (schedule[j].arrT != -1){
  				k = j;
  				flag = 1;
  				break;
  			}
  			++j;
  		}
  	}
  	if (flag == 0) break;
  	
  	if (currTime < schedule[k].arrT) currTime = schedule[k].arrT;
  	if (schedule[k].ct == -1) schedule[k].ct = currTime - schedule[k].arrT;
  	schedule[k].wt = schedule[k].wt + (currTime - schedule[k].lastMeet);
  	if (schedule[k].bustT > quant){
  		schedule[k].bustT = schedule[k].bustT - quant;
  		currTime = currTime + quant;
  		schedule[k].lastMeet = currTime;
  	}
  	else{ 
  		schedule[k].arrT = -1;
  		currTime = currTime + schedule[k].bustT;	 
  	}
  	
 	k = k + 1;
  	if (k == n) k = 0;
  }
  
  for (int i = 0; i < n; ++i){
  	schedule[i].tat = schedule[i].tat + schedule[i].wt;
  	averTAT = averTAT + schedule[i].wt + schedule[i].bustT;
  	averWT = averWT + schedule[i].wt;
  	printf("Process %d:\n    CT  = %d\n    TAT = %d\n    WT  = %d\n", i, schedule[i].ct, schedule[i].tat, schedule[i].wt);
  }
  
  
  averTAT = averTAT / n;
  averWT = averWT / n;
  printf("Average TAT = %f\nAverage WT  = %f\n", averTAT, averWT);

return 0;
}
