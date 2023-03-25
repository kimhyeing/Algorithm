#include<iostream>
#include<algorithm>

using namespace std;

int n, m, newx, newy, res;
int arr[501][501];
int posx[4] = { -1,0,1,0 };
int posy[4] = { 0,1,0,-1 };
pair<int, int> pos[3];

void dfs(int x, int y, int num, int count, int prex, int prey) {
	if (count >= 4) {
		res = max(num, res);
		return;
	}

	for (int i = 0; i < 4; i++) {
		newx = x + posx[i];
		newy = y + posy[i];
		if (newx < 0 || newy < 0 || newx >= n || newy >= m)
			continue;
		if (newx == prex && newy == prey) {
			continue;
		}
	
		dfs(newx, newy, num + arr[newx][newy], count + 1, x, y);
	}

	if (count == 2) {
		int t = 0;
		for (int i = 0; i < 4; i++) {
			newx = x + posx[i];
			newy = y + posy[i];
			if (newx < 0 || newy < 0 || newx >= n || newy >= m)
				continue;
			if (newx == prex && newy == prey) {
				continue;
			}

			pos[t] = make_pair(newx, newy);
			t++;
		}
		if (t == 3) {
			t = arr[pos[0].first][pos[0].second] + arr[pos[1].first][pos[1].second];
			res = max(res, (num + t));

			t = arr[pos[1].first][pos[1].second] + arr[pos[2].first][pos[2].second];
			res = max(res, (num + t));

			t = arr[pos[0].first][pos[0].second] + arr[pos[2].first][pos[2].second];
			res = max(res, (num + t));

		}
		else if (t == 2) {
			t = arr[pos[0].first][pos[0].second] + arr[pos[1].first][pos[1].second];
			res = max(res, (num + t));
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dfs(i, j, arr[i][j], 1, -1, -1);
		}
	}
	
	cout << res;
	return 0;
}