#include<iostream>

using namespace std;

int n, m;
int arr[9];
bool used[9];

void solve(int level) {
	if (level == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << "\n";
	}

	for (int i = 1; i <= n; i++) {
		if (!used[i]) {
			arr[level] = i;
			used[i] = true;
			solve(level + 1);
			used[i] = false;
		}
	}
}

int main() {
	cin >> n >> m;
	solve(0);

	return 0;
}