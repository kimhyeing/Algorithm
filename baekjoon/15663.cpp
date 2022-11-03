#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int used_level[9][10001];
int used_index[9][10001];
int arr[9];
int res[9];

void solve(int level) {
	if (level == m) {
		for (int i = 0; i < m; i++) {
			cout << res[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!used_level[level][arr[i]] && !used_index[i][arr[i]]) {
			used_level[level][arr[i]] = true;
			used_index[i][arr[i]] = true;
			res[level] = arr[i];
			solve(level + 1);
			used_index[i][arr[i]] = false;
		}
	}

	for (int i = 0; i < n; i++) {
		used_level[level][arr[i]] = false;
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	solve(0);
	return 0;
}