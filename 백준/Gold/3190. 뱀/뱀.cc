#include<iostream>
#include<queue>

using namespace std;

int n, k, a, b, l, x, des = 1;
int headx, heady, tailx, taily;
char c;
int board[101][101];
queue<pair<int, char>>q;
int posx[4] = { -1,0,1,0 };
int posy[4] = { 0,1,0,-1 };

void input() {
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> a >> b;
		board[a][b] = 1;
	}
	cin >> l;
	for (int i = 0; i < l; i++) {
		cin >> x >> c;
		q.push(make_pair(x, c));
	}
}

int position(int current, char dir) {
	if (dir == 'D') {
		return (current + 1) % 4;
	}
	else {
		return (current + 3) % 4;
	}
}

void print() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}
int move() {
	int min = 0;
	headx = heady = tailx = taily = 1;
	int taildes = des;
	queue<pair<int, char>>tailq;
	int taillen = 1;
	while (true) {
		if (!q.empty() && q.front().first == min) {
			tailq.push(q.front());
			des = position(des, q.front().second);
			q.pop();
		}
		if (!tailq.empty() && tailq.front().first + taillen - 1 == min) {
			taildes = position(taildes, tailq.front().second);
			tailq.pop();
		}

		headx += posx[des];
		heady += posy[des];
		if (headx > n || heady > n || headx < 1 || heady < 1 || board[headx][heady] == 2) {
			break;
		}

		if (board[headx][heady] == 1) {
			board[headx][heady] = 2;
			taillen++;
		}
		else if (board[headx][heady] == 0) {
			board[headx][heady] = 2;
			board[tailx][taily] = 0;
			tailx += posx[taildes];
			taily += posy[taildes];
		}
		min++;
	}
	return min + 1;
}

int main() {
	input();
	board[1][1] = 2;
	cout << move();

	return 0;
}