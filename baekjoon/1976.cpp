#include<iostream>

using namespace std;

int parent[201];
int n, m, c;

void init() {
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
}

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	parent[y] = x;
}

bool isConnected(int x, int y) {
	x = find(x);
	y = find(y);
	return x == y;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	init();

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> c;
			if (c) {
				merge(i, j);
			}
		}
	}

	bool res = true;
	if (m > 1) {
		int c1, c2;
		cin >> c1;
		for (int i = 1; i < m; i++) {
			cin >> c2;
			if (!isConnected(c1, c2)) {
				res = false;
				break;
			}
			c1 = c2;
		}
	}

	if (res) cout << "YES";
	else cout << "NO";
	return 0;
}