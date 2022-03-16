#include<iostream>
#include<algorithm>

using namespace std;

int arr[1000];
int dp[1000];

int main() {
	int n, res = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	fill_n(dp, n, 1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i])
				dp[i] = max(dp[i], dp[j] + 1);
		}
		res = max(dp[i], res);
	}
	cout << res;
	return 0;
}