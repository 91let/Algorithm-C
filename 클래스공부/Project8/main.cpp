#include <iostream>

class Node {
public:
	int chk, cnt, lv;
	Node **childs;
	Node(int lv = 0, int cnt = 1) {
		this->lv = lv;
		this->cnt = cnt;
		this->chk = 0;
		childs = new Node * [26];
	}
};

int main() {
}