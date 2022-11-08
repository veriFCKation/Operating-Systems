#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){

FILE *input;
input = fopen("input.txt", "r");

int page_num, hit = 0, miss = 0, clock = 0, frame_size = 100; // 10, 50 or 100
bool is_it_miss;
bool r_bits[frame_size];
int counters[frame_size];
for (int i = 0; i < frame_size; ++i){
	counters[i] = 0;
	r_bits[i] = false;
}
int page_frames[frame_size];

while (fscanf(input, "%d", &page_num) != EOF){
	++clock;
	is_it_miss = true;
	int replace_index = 0;
	for (int i = 0; i < frame_size; ++i){
		if (page_frames[i] < page_frames[replace_index])
			replace_index = i;
		if (page_frames[i] == page_num){
			is_it_miss = false;
			r_bits[i] = true;
		}
	}
	if (is_it_miss){
		miss++;
		page_frames[replace_index] = page_num;
		counters[replace_index] = 0;
	}
	else{	hit++; }
	if (clock % 2 == 0){
		for (int i = 0; i < frame_size; ++i){
			counters[i] = counters[i] >> 1;
			if (r_bits[i]){
				counters[i] = counters[i] + (1 << 7);
				r_bits[i] = false;
			}
		}
	}
}
printf("Hits: %d\nMisses: %d\nRatio: %f\n", hit, miss, ((hit*1.0)/miss));

/*
10 frames result:
Hits: 6
Misses: 994
Ratio: 0.006036

50 frames result:
Hits: 24
Misses: 976
Ratio: 0.024590

100 frames result:
Hits: 53
Misses: 947
Ratio: 0.055966

*/

return 0;
}
