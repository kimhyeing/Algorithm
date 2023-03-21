#include<iostream>
#include<algorithm>

using namespace std;

int n, m, res = 11, des;
int rx, ry, bx, by, new_rx, new_ry, new_bx, new_by;
char board[11][11];
bool success_r, success_b;
char r, b;

void input() {
	cin >> n >> m;
	char c;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c;
			board[i][j] = c;
			if (c == 'R') {
				rx = i; ry = j;
				board[i][j] = '.';
			}
			else if (c == 'B') {
				bx = i; by = j;
				board[i][j] = '.';
			}
		}
	}
}

void dfs(int rx_, int ry_, int bx_, int by_, int count, int pos) {
	if(count >= 10) return;
	if (pos % 2 == 0) {
		new_rx = rx_;
		new_bx = bx_;
		for (int i = 0; i < 2; i++) {
			success_r = false;
			success_b = false;
			new_rx = rx_;
			new_bx = bx_;
			new_ry = ry_;
			new_by = by_;
			if (i == 0) {
				des = 1; // 오른쪽
			}
			else {
				des = -1;//왼쪽
			}
			while (true) {
				int tempry = new_ry;
				r = board[new_rx][new_ry + des];
				b = board[new_bx][new_by + des];
				if (r == '#' && b == '#') {
					if (success_r == true && success_b == false) {
						res = min(res, count + 1);
						return;
					}
					else {
						if ((ry_ != new_ry) || (by_ != new_by)) {
							dfs(new_rx, new_ry, new_bx, new_by, count + 1, 1);
						}
					}
					break;
				}

				if (r == 'O') {
					success_r = true;
					new_ry += des;
				}
				else if (((new_ry + des) == new_by) && new_bx == new_rx) {
					if (b != '#') new_ry += des;
					else {
						if (success_r == true && success_b == false) {
							res = min(res, count + 1);
							return;
						}
						else {
							if ((ry_ != new_ry) || (by_ != new_by)) {
								dfs(new_rx, new_ry, new_bx, new_by, count + 1, 1);
							}
						}
						break;
					}
				}
				else if (r == '.') {
					new_ry += des;
				}

				if (b == 'O') {
					success_b = true;
					break;
				}
				else if (((new_by + des) == tempry) && new_bx == new_rx) {
					if (r != '#') new_by += des;
					else {
						if (success_r == true && success_b == false) {
							res = min(res, count + 1);
							return;
						}
						else {
							if ((ry_ != new_ry) || (by_ != new_by)) {
								dfs(new_rx, new_ry, new_bx, new_by, count + 1, 1);
							}
						}
						break;
					}
				}
				else if (b == '.') {
					new_by += des;
				}
			}
		}
	}
	else {
		new_ry = ry_;
		new_by = by_;
		for (int i = 0; i < 2; i++) {
			success_r = false;
			success_b = false;
			new_rx = rx_;
			new_bx = bx_;
			new_ry = ry_;
			new_by = by_;
			if (i == 0) {
				des = 1; // 아래쪽
			}
			else {
				des = -1;//위쪽
			}
			
			while (true) {
				int temprx = new_rx;
				r = board[new_rx + des][new_ry];
				b = board[new_bx + des][new_by];
				if (r == '#' && b == '#') {
					if (success_r == true && success_b == false) {
						res = min(res, count + 1);
						return;
					}
					else {
						if ((rx_ != new_rx) || (bx_ != new_bx)) {
							dfs(new_rx, new_ry, new_bx, new_by, count + 1, 0);
						}
						break;
					}
				}

				if (r == 'O') {
					success_r = true;
					new_rx += des;
				}
				else if (((new_rx + des) == new_bx) && new_by == new_ry) {
					if (b != '#') new_rx += des;
					else {
						if (success_r == true && success_b == false) {
							res = min(res, count + 1);
							return;
						}
						else {
							if ((rx_ != new_rx) || (bx_ != new_bx)) {
								dfs(new_rx, new_ry, new_bx, new_by, count + 1, 0);
							}
							break;
						}
					}
				}
				else if (r == '.') {
					new_rx += des;
				}

				if (b == 'O') {
					success_b = true;
					break;
				}
				else if (((new_bx + des) == temprx) && new_by == new_ry) {
					if (r != '#') new_bx += des;
					else {
						if (success_r == true && success_b == false) {
							res = min(res, count + 1);
							return;
						}
						else {
							if ((rx_ != new_rx) || (bx_ != new_bx)) {
								dfs(new_rx, new_ry, new_bx, new_by, count + 1, 0);
							}
							break;
						}
					}
				}
				else if (b == '.') {
					new_bx += des;
				}
			}
		}
	}
}

int main() {
	input();
	dfs(rx, ry, bx, by, 0, 0);
	dfs(rx, ry, bx, by, 0, 1);
	if (res > 10) res = -1;
	cout << res;

	return 0;
}