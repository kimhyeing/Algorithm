#include<iostream>
#include<cmath>

using namespace std;

int col[14];
int n, result;

bool check(int level) {
	for (int y = 0; y < level; y++) {
		if (col[y] == col[level] || abs(col[y] - col[level]) == level - y)
			return false;
	}
	return true;
}

void dfs(int y) {
	if (y == n) {
		result++;
		return;
	}

	for (int x = 0; x < n; x++) {
		col[y] = x;
		if (check(y))
			dfs(y + 1);
	}
}

int main() {	
	cin >> n;
	dfs(0);
	cout << result;
	return 0;
}