#include<iostream>

using namespace std;

long long int dp[1001][10];

int main() {
	int n;
	cin >> n;

	for (int i = 0; i <= 9; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0)
				dp[i][j] = 1;
			else
				dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % 10007;
		}
	}

	int res = 0;
	for (int i = 0; i <= 9; i++)
		res += dp[n][i];
	cout << res % 10007;
	return 0;
}