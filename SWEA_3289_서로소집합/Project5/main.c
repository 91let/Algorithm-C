#include<stdio.h>

int sets[1000001];

void init(int n) {
    while (n) {
        sets[n--] = 0;
    }
}

int setting(int a) {
    if (sets[a]) {
        sets[a] = setting(sets[a]);
        return sets[a];
    }
    else {
        return a;
    }
}

int check(int a, int b) {
    return (setting(a) != setting(b)) ? 0 : 1;
}

void union_set(int a, int b) {
    if (check(a, b)) return;
    else {
        sets[setting(b)] = setting(a);
    }
}

int main() {
    int T, t = 0, n, m, order, a, b, p = -1;
    char buff[500020];
    scanf("%d", &T);
    while (t < T) {
        scanf("%d %d", &n, &m);
        init(n);
        buff[++p] = '#';
        buff[++p] = ++t + '0';
        buff[++p] = ' ';
        while (m--) {
            scanf("%d %d %d", &order, &a, &b);
            if (order) buff[++p] = check(a, b) + '0';
            else union_set(a, b);
        }
        buff[++p] = '\n';
    }
    printf("%s", buff);
}