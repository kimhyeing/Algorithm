#include<iostream>
#include<cstring>

using namespace std;

int matrix[50][50];
int visit[50][50];
int m, n, x, y;
int posx[4] = { -1,0,1,0 };
int posy[4] = { 0,1,0,-1 };

void dfs(int a, int b) {
	visit[a][b] = 1;
	for (int i = 0; i < 4; i++) {
		x = a + posx[i];
		y = b + posy[i];
		if (x < 0 || y < 0 || x >= m || y >= n)
			continue;

		if (matrix[x][y] == 1 && visit[x][y] == 0) {
			visit[x][y] = 1;
			dfs(x, y);
		}
	}
}

int main() {
	int t, k;
	cin >> t;
	while (t--) {
		cin >> m >> n >> k;
		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			matrix[x][y] = 1;
		}

		int count = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] == 1 && visit[i][j] == 0) {
					dfs(i, j);
					count++;
				}
			}
		}
		cout << count << "\n";

		memset(matrix, 0, sizeof(matrix));
		memset(visit, 0, sizeof(visit));
	}

	return 0;
}