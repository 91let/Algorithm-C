#include <stdio.h>

int main() {
	int t = 0, T;
	char* ans1 = "#%d NO\n";
	char* ans2 = "#%d YES\n";
	scanf("%d", &T);
	while (t ^ T) {
		long long N;
		scanf("%lld", &N);
		if (N & -N ^ N) printf(ans1, ++t);
		else printf(ans2, ++t);
	}
}
