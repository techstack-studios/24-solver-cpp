#include <iostream>
using namespace std;

int raw[4], pl[4], oper[3], cnt = 0; //oper:0 addition, 1 subtraction, 2 multiplication, 3 division
bool visit[13];

void dfs(int t);
void operdfs(int t);
void processoper();

int main() {
	for (int i = 0; i < 4; i++) cin >> raw[i];
	dfs(0);
	return 0;
}

void dfs(int t) {
	if (t == 4) {
		operdfs(0);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (!visit[raw[i]]) {
			pl[t] = raw[i]; visit[raw[i]] = true;
			dfs(t + 1);
			visit[raw[i]] = false;
		}
	}
}

void operdfs(int t) { //t0=0
	if (t == 3) {
		processoper();
		return;
	}
	for (int i = 0; i < 4; i++) {
		oper[t] = i;
		operdfs(t + 1);
	}
}

void processoper() {
	int res = pl[0];
	for (int i = 0; i < 3; i++) {
		switch (oper[i]) {
		case 0: res += pl[i + 1]; break;
		case 1: res -= pl[i + 1]; break;
		case 2: res *= pl[i + 1]; break;
		case 3: res /= pl[i + 1]; break;
		}
	}
	if (res == 24) {
		for (int i = 0; i < 3; i++) {
			cout << pl[i] << " ";
			switch (oper[i]) {
			case 0: cout << "+ "; break;
			case 1: cout << "- "; break;
			case 2: cout << "* "; break;
			case 3: cout << "/ "; break;
			}
		}
		cout << pl[3] << endl;
	}
	return;
}