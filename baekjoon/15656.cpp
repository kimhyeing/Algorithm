#include<iostream>
#include<algorithm>

using namespace std;

int n, m;
int arr[8];
int res[8];

void solve(int level) {
	if (level == m) {
		for (int i = 0; i < m; i++) {
			cout << res[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++) {
		res[level] = arr[i];
		solve(level + 1);
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