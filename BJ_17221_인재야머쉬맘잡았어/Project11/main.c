#include<stdio.h>

void attack(int u_hp, int u_atk, int m_hp, int m_atk, int turn, int* Ans) {
	if (u_hp / m_atk < m_hp / u_atk) return;
	if (u_hp / m_atk == m_hp / u_atk && u_hp % m_atk == 0 && m_hp % u_atk != 0) return;
	int now = turn + m_hp / u_atk + ((m_hp % u_atk != 0) ? 1 : 0);
	*Ans = (*Ans < now) ? *Ans: now;
}

void buff(int u_hp, int u_atk, int m_hp, int m_atk, int turn, int* Ans) {
	if (turn > *Ans || u_atk < 5) return;
	buff(u_hp - m_atk * 3, u_atk + u_atk / 5, m_hp, m_atk, turn + 1, Ans);
	attack(u_hp - m_atk * 3, u_atk + u_atk / 5, m_hp, m_atk, turn + 1, Ans);
}

void counter(int u_hp, int u_atk, int m_hp, int m_atk, int turn, int* Ans) {
	if (turn > *Ans) return;
	if (m_hp < 1) {
		*Ans = (*Ans < turn) ? *Ans: turn;
		return;
	}
	attack(u_hp, u_atk, m_hp, m_atk, turn, Ans);
	buff(u_hp, u_atk, m_hp, m_atk, turn, Ans);
	if (u_atk > 4) counter(u_hp + u_hp / 10, u_atk, m_hp - m_atk, m_atk, turn + 1, Ans);
}

int main() {
	int A, B, X, Y, Ans, *tmp = &Ans;
	scanf("%d %d %d %d", &A, &B, &X, &Y);
	Ans = X / Y + ((X % Y != 0) ? 1 : 0);
	counter(A, B, X, Y, 0, &Ans);
	printf("%d", Ans);
}
