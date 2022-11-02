#include<iostream>
#include<algorithm>

using namespace std;

int n, m;
int arr[9];
int res[9];
bool used[9];

void solve(int level) {
	if (level == m) {
		for (int i = 0; i < m; i++) {
			cout << res[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			res[level] = arr[i];
			used[i] = true;
			solve(level + 1);
			used[i] = false;
		}
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