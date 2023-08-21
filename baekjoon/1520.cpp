#include<iostream>
#include<queue>

using namespace std;

int n, m;
int arr[500][500];
int visit[500][500];
long long res;
int dirx[4] = { 0,1,0, -1 };
int diry[4] = { 1,0,-1, 0 };

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	visit[n - 1][m - 1] = 1;
}

int dfs(int prex, int prey, int x, int y) {
	if ((x == (n - 1) && y == (m - 1)) || visit[x][y]) {
		res += visit[x][y];
		return visit[x][y];
	}

	int temp = 0;
	bool invaild = true;
	for (int i = 0; i < 4; i++) {
		int newx = x + dirx[i];
		int newy = y + diry[i];

		if (newx < 0 || newx >= n || newy < 0 || newy >= m)
			continue;
		
		if (visit[newx][newy] < 0 || arr[x][y] <= arr[newx][newy] || (newx == prex && newy == prey))
			continue;
		
		invaild = false;
		temp = dfs(x, y, newx, newy);
		if (temp > 0) {
			visit[x][y] += temp;
		}
	}

	if (invaild) {
		visit[x][y] = -1;
	}

	return visit[x][y];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	dfs(-1, -1, 0, 0);
	cout << res;
	return 0;
}