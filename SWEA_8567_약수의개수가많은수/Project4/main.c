#include<stdio.h>
#define MAX_RANGE 100001
#define MAX_DIV_RANGE 7

int counts[MAX_RANGE] = { 0, }, div_nums[MAX_DIV_RANGE] = { 2, 3, 5, 7, 11, 13, 17 }, div_counts[MAX_DIV_RANGE] = { 0, };

int pow(int base, int exponent) {
	int tmp = 1;
	while (exponent--) tmp *= base;
	return tmp;
}

void get() {
	int now = 1, val = 1;
	for (int i = 0; i < MAX_DIV_RANGE; i++) {
		now *= pow(div_nums[i], div_counts[i]);
	}
	for (int i = 0; i < MAX_DIV_RANGE; i++) {
		val *= div_counts[i] + 1;
	}
	counts[now] = val;
	for (int i = 0; i < MAX_DIV_RANGE; i++) {
		if (now * div_nums[i] > 100000) return;
		if (counts[now * div_nums[i]]) continue;
		++div_counts[i];
		get();
		--div_counts[i];
	}
}

int main() {
	get();
	int max_count = 1, max_num = 1;
	for (int i = 1; i < MAX_RANGE; i++) {
		if (counts[i] < max_count) {
			counts[i] = max_num;
		}
		else {
			max_count = counts[i];
			counts[i] = max_num = i;
		}
	}

	int T, t = 0, p;
	scanf("%d", &T);
	while (t < T) {
		scanf("%d", &p);
		printf("#%d %d\n", ++t, counts[p]);
	}
}
