#include <stdio.h>

int check(long long *x1, long long *y1, long long* x2, long long* y2, long long* x3, long long* y3, long long* x4, long long* y4) {
	if ((*x2 - *x1) * (*x3 - *x1) + (*y2 - *y1) * (*y3 - *y1)) return 0;
	if ((*x2 - *x4) * (*x3 - *x4) + (*y2 - *y4) * (*y3 - *y4)) return 0;
	if ((*x2 - *x1) * (*x2 - *x4) + (*y2 - *y1) * (*y2 - *y4)) return 0;
	if ((*x2 - *x1) * (*x2 - *x4) + (*y2 - *y1) * (*y2 - *y4)) return 0;
	if ((*x2 - *x1) * (*x2 - *x1) + (*y2 - *y1) * (*y2 - *y1) != (*x3 - *x1) * (*x3 - *x1) + (*y3 - *y1) * (*y3 - *y1)) return 0;
	return 1;
}

int main() {
	long long ax, ay, bx, by, cx, cy, dx, dy;
	int N;
	char io[] = " %lld %lld\n %lld %lld\n %lld %lld\n %lld %lld";
	for (scanf("%d", &N); N--;) {
		scanf(io, &ax, &ay, &bx, &by, &cx,&cy, &dx, &dy);
		printf("%d", check(&ax, &ay, &bx, &by, &cx, &cy, &dx, &dy) || check(&ax, &ay, &bx, &by, &dx, &dy, &cx, &cy) || check(&ax, &ay, &dx, &dy, &cx, &cy, &bx, &by));
	}

}