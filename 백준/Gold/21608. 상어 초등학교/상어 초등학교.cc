#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int arr[20][20];
int love[401][4];
vector<int>v;
int dirx[4] = { -1,0,1,0 };
int diry[4] = { 0,1,0,-1 };
int value[5] = { 0,1,10,100,1000 };

void input() {
	cin >> n;
	int a;
	int len = n * n;
	for (int i = 0; i < len; i++) {
		cin >> a;
		v.push_back(a);
		for (int j = 0; j < 4; j++) {
			cin >> love[a][j];
		}
	}
	arr[1][1] = v[0];
}

bool isLove(int a, int b) {
	for (int i = 0; i < 4; i++) {
		if (love[a][i] == b) return true;
	}
	return false;
}

int max_ln, max_en, min_x, min_y;
void setSeat(int ln, int en, int i, int j) {
	max_ln = ln;
	max_en = en;
	min_x = i;
	min_y = j;
}

void solve() {
	int num, newx, newy, en, ln;
	
	for (int t = 1; t < v.size();t++) {
		num = v[t];
		min_x = min_y = n;
		max_ln = max_en = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				en = ln = 0;
				if (arr[i][j] > 0) continue;

				for (int d = 0; d < 4; d++) {
					newx = i + dirx[d];
					newy = j + diry[d];
					if (newx < 0 || newy < 0 || newx >= n || newy >= n) continue;
					if (arr[newx][newy] == 0) {
						en++;
					}
					else if (isLove(num, arr[newx][newy])) {
						ln++;
					}
				}
				if (ln > max_ln) {
					setSeat(ln, en, i, j);
				}
				else if (ln == max_ln) {
					if (en > max_en) {
						setSeat(ln, en, i, j);
					}
					else if (en == max_en) {
						if (i < min_x) {
							setSeat(ln, en, i, j);
						}
						else if (i == min_x) {
							if (j < min_y) {
								setSeat(ln, en, i, j);
							}
						}
					}
				}
			}
		}
		arr[min_x][min_y] = num;
	}
}

int getResult() {
	int res = 0, cnt, newx, newy;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cnt = 0;
			for (int d = 0; d < 4; d++) {
				newx = i + dirx[d];
				newy = j + diry[d];
				if (newx < 0 || newy < 0 || newx >= n || newy >= n)  continue;
				
				if (isLove(arr[i][j], arr[newx][newy])) {
					cnt++;
				}
			}

			res += value[cnt];
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	solve();
	cout << getResult();
	return 0;
}