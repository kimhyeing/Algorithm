#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>

using namespace std;

pair<int, int>arr[4][4];
pair<int, int>fish[17];
bool used[17];
int posx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int posy[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int n, res, x, y, sx, sy, sdir;

void dfs(int curx, int cury, int curdir, int cureat, pair<int, int> _arr[4][4], pair<int, int> _fish[17], bool _used[17]) {
	int newx, newy, newdir;
	pair<int, int> newarr[4][4];
	pair<int, int> newfish[17];
	bool newused[17];
	copy(&_arr[0][0], &_arr[0][0] + 16, &newarr[0][0]);
	copy(&_fish[0], &_fish[0] + 17, &newfish[0]);
	copy(&_used[0], &_used[0] + 17, &newused[0]);
	for (int i = 1; i <= 16; i++) {
		x = newfish[i].first;
		y = newfish[i].second;
		if (newused[i]) continue;

		newdir = newarr[x][y].second;
		for (int t = 0; t < 8; t++) {
			if (t != 0)
				newdir = (newdir + 1) % 8;
			newx = x + posx[newdir];
			newy = y + posy[newdir];
			if (newx < 0 || newy < 0 || newx >= 4 || newy >= 4 || (newx == curx && newy == cury) )
				continue;

			newarr[x][y] = make_pair(newarr[x][y].first, newdir);

			newfish[newarr[newx][newy].first] = make_pair(x, y);
			newfish[i] = make_pair(newx, newy);

			swap(newarr[x][y], newarr[newx][newy]);
			break;
		}
	}
	newx = curx;
	newy = cury;
	int preN, preD;
	for (int i = 0; i < 3; i++) {
		newx += posx[curdir];
		newy += posy[curdir];
		if (newx < 0 || newy < 0 || newx >= 4 || newy >= 4 || newused[newarr[newx][newy].first] || newarr[newx][newy].first == 0)
			continue;

		preN = newarr[newx][newy].first;
		preD = newarr[newx][newy].second;
		newused[preN] = true;
		newarr[newx][newy] = make_pair(0, preD);

		res = max(res, cureat + preN);
		dfs(newx, newy, preD, cureat + preN, newarr, newfish, newused);
		
		newarr[newx][newy] = make_pair(preN, preD);
		newused[preN] = false;
	}
}

void input() {
	int a, b;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> a >> b;
			if (i == 0 && j == 0) {
				res += a;
				used[a] = true;
				sdir = b - 1;
				a = 0;
			}
			
			fish[a] = make_pair(i, j);
			arr[i][j] = make_pair(a, b - 1);
		}
	}
}
int main() {
	input();
	dfs(0, 0, sdir, res, arr, fish, used);
	cout << res;

	return 0;
}