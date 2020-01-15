#include <stdio.h>

int main() {
	int T, t = 0, N;
	long long ans, price, tmp;
	char f1[] = "%d\n%lld";
	char f2[] = "#%d %lld\n";
	scanf("%d", &T);
	while (t != T) {
		scanf(f1, &N, &ans);
		--ans;
		price = 2;
		while (--N) {
			scanf("%lld", &tmp);
			if (tmp == price)
			{
				++price;
			}
			else {
				ans += tmp / price;
                if (!tmp % price) --ans;
			}
		}
		printf(f2, ++t, ans);
	}
}