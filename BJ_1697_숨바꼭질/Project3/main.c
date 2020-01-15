#include <stdio.h>
#define left -1
#define right +1
#define jump *2

int main() {
	char map[100001] = {0, };
	int q[100001], qs = -1, qe = -1, S, B, count = -1, tmp;
	scanf("%d %d", &S, &B);
	q[++qe] = S;
	map[S] = 1;
	while (qs != qe) {
		++count;
		for (int i = qe - qs; i > 0; --i)
		{
			tmp = q[++qs];
			if (tmp == B) {
				printf("%d", count);
				return 0;
			}
			if (tmp left > -1) {
				if (!map[tmp left]) {
				map[tmp left] = 1;
				q[++qe] = tmp left;
				}
			}
			if (tmp right < 100001) {
				if (!map[tmp right]) {
					map[tmp right] = 1;
					q[++qe] = tmp right;
				}
			}
			if (tmp jump < 100001) {
				if (!map[tmp jump]) {
					map[tmp jump] = 1;
					q[++qe] = tmp jump;
				}
			}
		}
	}
	return 0;
}