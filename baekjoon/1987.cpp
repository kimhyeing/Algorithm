#include<iostream>
#include<algorithm>

using namespace std;

int r, c, newx, newy, res = 1;
char arr[21][21];
int visit[28];
int posx[4] = { -1, 0, 1, 0 };
int posy[4] = { 0, 1, 0, -1 };

void dfs(int x, int y, int count) {
	visit[(arr[x][y] - 'A')]++;

	for (int i = 0; i < 4; i++) {
		newx = x + posx[i];
		newy = y + posy[i];
		if (newx < 0 || newy < 0 || newx >= r || newy >= c)
			continue;
		if (visit[(arr[newx][newy] - 'A')] == 0) {
			res = max(res, count + 1);
			dfs(newx, newy, count + 1);
		}
	}

	visit[(arr[x][y] - 'A')]--;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
		}
	}
	dfs(0, 0, 1);
	cout << res;
	return 0;
}