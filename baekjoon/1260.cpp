#include<iostream>
#include<queue>

using namespace std;

int matrix[1001][1001];
int visit[1001];
int n;

void dfs(int v) {
	cout << v << " ";
	visit[v] = 1;
	for (int i = 1; i <= n; i++) {
		if (visit[i] == 0 && matrix[v][i] == 1) {
			dfs(i);
		}
	}
}

void bfs(int v) {
	queue<int>q;
	q.push(v);
	visit[v] = 0;

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		cout << now << " ";

		for (int i = 1; i <= n; i++) {
			if (visit[i] == 1 && matrix[now][i] == 1) {
				visit[i] = 0;
				q.push(i);
			}
		}
	}
}

int main() {
	int m, v, a, b;
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		matrix[a][b] = matrix[b][a] = 1;
	}
	dfs(v);
	cout << "\n";
	bfs(v);

	return 0;
}