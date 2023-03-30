#include<iostream>
#include<deque>
#include<algorithm>
#include<cstring>

using namespace std;

bool ladder[31][11][11];

int n, m, h, a, b, res = 4;

void solve(bool _ladder[31][11][11], int count) {
	if (count > 3) {
		return;
	}
	int cur;
	bool success[11] = { false, };
	for (int i = 1; i <= n; i++) {
		cur = i;
		deque<pair<int, int>>dq;
		for (int j = 1; j <= h; j++) {
			if (cur < n && _ladder[j][cur][cur + 1]) {
				if (!dq.empty() && dq.front().first == (cur + 1) && dq.front().second == cur) {
					dq.pop_front();
				}
				else {
					dq.push_back(make_pair(cur, cur + 1));
				}
				cur++;
			}
			else if (cur > 1 && _ladder[j][cur][cur - 1]) {
				if (!dq.empty() && dq.back().first == (cur - 1) && dq.back().second == cur) {
					dq.pop_back();
				}
				else {
					dq.push_back(make_pair(cur, cur - 1));
				}
				cur--;
			}
		}

		if (cur == i) {
			success[i] = true;
		}

		while (i < cur) {
			for (int t = 1; t <= h; t++) {
				bool newLadder[31][11][11];
				memcpy(newLadder, _ladder, sizeof(newLadder));
				if (!_ladder[t][cur][cur - 1]) {
					if (cur > 2 && _ladder[t][cur - 1][cur - 2]) {
						continue;
					}
					if (cur < n && _ladder[t][cur][cur + 1]) {
						continue;
					}
					newLadder[t][cur][cur - 1] = true;
					newLadder[t][cur - 1][cur] = true;
					solve(newLadder, count + 1);
				}
			}
			cur--;
		}
		
		while (i > cur) {
			for (int t = 1; t <= h; t++) {
				bool newLadder[31][11][11];
				memcpy(newLadder, _ladder, sizeof(newLadder));

				if (!_ladder[t][cur][cur + 1]) {
					if (cur > 1 && _ladder[t][cur][cur - 1]) {
						continue;
					}
					if (cur < n - 1 && _ladder[t][cur + 1][cur + 2]) {
						continue;
					}
					newLadder[t][cur][cur + 1] = true;
					newLadder[t][cur + 1][cur] = true;
					solve(newLadder, count + 1);
				}
			}
			cur++;
		}
		if (!success[i]) return;
	}

	bool cal = true;
	for (int i = 1; i <= n; i++) {
		if (!success[i]) cal = false;
	}
	if(cal) res = min(res, count);
}

void input() {
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		ladder[a][b][b + 1] = true;
		if (b < n) {
			ladder[a][b + 1][b] = true;
		}
	}
}

int main() {
	cin >> n >> m >> h;

	input();
	solve(ladder, 0);
	if (res > 3) res = -1;
	cout << res;
	return 0;
}