#include<iostream>

using namespace std;

int arr[8];
int n, m;

void solve(int level) {
	if (level > m) {
		for (int i = 1; i <= m; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++) {
		arr[level] = i;
		solve(level + 1);
	}
}
int main() {
	cin >> n >> m;
	solve(1);

	return 0;
}