#include<iostream>

using namespace std;

int dp[1000001];

int solve(int n) {
	if (dp[n] != 0) return dp[n];
	dp[n] = (solve(n - 1) + solve(n - 2)) % 15746;
	return dp[n];
}

int main() {
	int n;
	cin >> n;
	dp[1] = 1;
	dp[2] = 2;
	cout << solve(n);
	return 0;
}