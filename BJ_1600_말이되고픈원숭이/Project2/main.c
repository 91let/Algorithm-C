#include<stdio.h>

int dh[4] = { -1, 1, 0, 0 },
dw[4] = { 0, 0, -1, 1 },
jh[8] = { -2, -2, -1, -1, 1, 1, 2, 2 },
jw[8] = { -1, 1, -2, 2, -2, 2, -1, 1 },
q[1240000],
map[200][200];

int main() {
	int K, W, H;
	char buff[401];
	scanf("%d\n%d %d", &K, &W, &H);
	++K;
	int qs = -1, qe = -1, count = 0;
	for (int i = 0; i < H; i++) {
		scanf(" %[^\n]", &buff);
		for (int j = 0; j < W; j++) {
			map[i][j] = (buff[j * 2] != '0') ? 2147483647 : 0;
		}
	}
	map[0][0] = 2147483647;
	q[++qe] = (K - 1) * 40000;
	while (qe != qs) {
		for (int i = qe - qs; i > 0; --i) {
			int tmp = q[++qs];
			int lv = tmp / 40000, th = tmp % 40000 / 200, tw = tmp % 200;
			if (th == H - 1 && tw == W - 1) {
				printf("%d", count);
				return 0;
			}
			else {
				for (int d = 0; d < 4; d++) {
					int tth = th + dh[d], ttw = tw + dw[d];
					if (tth > -1 && ttw > -1 && tth < H && ttw < W && ((map[tth][ttw] >> lv) & 1) != 1) {
						map[tth][ttw] |= (1 << lv);
						q[++qe] = lv * 40000 + tth * 200 + ttw;
					}
				}
				if (--lv != -1) {
					for (int j = 0; j < 8; j++) {
						int tth = th + jh[j], ttw = tw + jw[j];
						if (tth > -1 && ttw > -1 && tth < H && ttw < W && ((map[tth][ttw] >> lv) & 1) != 1) {
							map[tth][ttw] |= (1 << lv);
							q[++qe] = lv * 40000 + tth * 200 + ttw;
						}
					}
				}
			}
		}
		++count;
	}
	printf("-1");
	return 0;
}
