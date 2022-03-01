#include<iostream>
#include<algorithm>

using namespace std;

int arr[10000];
int dp[10000];

int solve(int n) {
	dp[0] = arr[0];
	dp[1] = dp[0] + arr[1];
	dp[2] = max(dp[1], arr[1] + arr[2]);
	dp[2] = max(dp[2], arr[2] + arr[0]);
	
	int res = max(dp[1], dp[2]);
	for (int i = 3; i < n; i++) {
		dp[i] = max(dp[i- 3] + arr[i - 1] + arr[i], dp[i - 2] + arr[i]);
		dp[i] = max(dp[i], dp[i - 1]);
		res = max(res, dp[i]);
	}
	return res;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cout << solve(n);
	return 0;
}