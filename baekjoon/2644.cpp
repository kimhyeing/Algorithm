#include<iostream>
#include<queue>

using namespace std;

int n, m, a, b;
int matrix[101][101];
int visit[101];

void bfs() {
	queue<int>q;
	q.push(a);
	visit[a] = 1;

	while (!q.empty()) {
		int v = q.front();
		q.pop();
		if (v == b) {
			cout << visit[v] - 1;
			return;
		}

		for (int i = 1; i <= n; i++) {
			if (visit[i] == 0 && matrix[v][i] == 1) {
				visit[i] = visit[v] + 1;
				q.push(i);
			}
		}
	}
	cout << -1;
}

int main() {
	int x, y;
	cin >> n >> a >> b >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		matrix[x][y] = matrix[y][x] = 1;
	}
	bfs();

	return 0;
}