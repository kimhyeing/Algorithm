#include<iostream>

using namespace std;

#define MAX 1000000

int parent[MAX];

int find(int x) {
	if (parent[x] == x)
		return x;
	return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	parent[y] = x;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, op, x, y;
	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		cin >> op >> x >> y;
		if (op == 0) {
			merge(x, y);
		}
		else {
			x = find(x);
			y = find(y);
			if (x == y) {
				cout << "yes\n";
			}
			else {
				cout << "no\n";
			}
		}
	}
	return 0;
}