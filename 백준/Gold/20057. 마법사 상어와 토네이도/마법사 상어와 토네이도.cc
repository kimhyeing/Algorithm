#include <iostream>

using namespace std;

int sand[500][500];
int result;
int dirx[4] = { 0,1,0,-1 };
int diry[4] = { -1,0,1,0 };
int dist = 1, curd, n, x, y;
double value[9] = { 0.01, 0.01, 0.07, 0.07, 0.02, 0.02, 0.1, 0.1, 0.05 };
int dirc[9] = { 0,0,1,1,1,1,2,2,3 };
int dirl[9] = { 1,0,1,0,2,0,1,0,0 };
int dirr[9] = { 0,1,0,1,0,2,0,1,0 };

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> sand[i][j];
		}
	}
	x = y = n / 2;
}

void solve() {
	int newx, newy, tx, ty, tsand, leftd, rightd, all_sand, spread_sand;
	int cur_dist = 0, cnt = 0;
	while (x != 0 || y != 0) {
		leftd = (curd + 1) % 4;

		if (curd == 0) rightd = 3;
		else rightd = curd - 1;
		newx = x + dirx[curd];
		newy = y + diry[curd];
		all_sand = sand[newx][newy];
		sand[newx][newy] = 0;
		spread_sand = 0;
		for (int i = 0; i < 10; i++) {
			if (i == 9) {//alpha
				tx = newx + dirx[curd];
				ty = newy + diry[curd];
				tsand = all_sand - spread_sand;
			}
			else {
				tx = x + (dirx[curd] * dirc[i]) + (dirx[leftd] * dirl[i]) + (dirx[rightd] * dirr[i]);
				ty = y + (diry[curd] * dirc[i]) + (diry[leftd] * dirl[i]) + (diry[rightd] * dirr[i]);
				tsand = (all_sand * value[i]);
				spread_sand += tsand;
			}
			if (tx < 0 || ty < 0 || tx >= n || ty >= n) {
				result += tsand;
			}
			else {
				sand[tx][ty] += tsand;
			}
		}
		
		x = newx;
		y = newy;
		cur_dist++;

		if (cur_dist == dist) {
			curd = (curd + 1) % 4;
			cur_dist = 0;
			cnt++;
		}

		if (cnt == 2) {
			cnt = 0;
			dist++;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	solve();
	cout << result;
	return 0;
}