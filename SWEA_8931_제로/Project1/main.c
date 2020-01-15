#include <stdio.h>
#include <string.h>

int main() {
	int T, t = 0, K, datas[100001], data, p;
	char tmp[15] = {};
	long long sum;
	scanf("%d", &T);
	while (t < T) {
		sum = 0;
		scanf("%d", &K);
		while (K--) {
			scanf("%d", &data);
			if (data) {
				datas[++p] = data;
			}
			else {
				--p;
			}
		}
		while (p) {
			sum += datas[p--];
		}
		printf("%s", tmp);
	}

	return 0;
}