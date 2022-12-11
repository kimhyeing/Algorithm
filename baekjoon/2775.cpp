#include<iostream>

using namespace std;

int dp[15][15];

int main() {
	int t, k, n;
	cin >> t;
	while (t--) {
		cin >> k >> n;
		for (int i = 1; i <= n; i++) {
			dp[0][i] = i;
		}

		for (int i = 1; i <= k; i++) {
			for (int j = 1; j <= n; j++) {
				dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
			}
		}

		cout << dp[k][n] << "\n";

		fill(&dp[0][0], &dp[14][14], 0);
	}
	return 0;
}