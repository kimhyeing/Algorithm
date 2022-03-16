#include<iostream>

using namespace std;

int dp[11];

int solve(int n) {
	if (dp[n] != 0)
		return dp[n];
	return solve(n - 1) + solve(n - 2) + solve(n - 3);
}

int main() {
	int t, n;
	cin >> t;
	dp[1] = 1; dp[2] = 2; dp[3] = 4;
	while (t--) {
		cin >> n;
		cout << solve(n) << "\n";
	}

	return 0;
}