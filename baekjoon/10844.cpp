#include<iostream>

using namespace std;

long long int dp[101][10];
long long int sum[101];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i <= 9; i++)
		dp[1][i] = 1;
	sum[1] = 9;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 9)
				dp[i][j] = dp[i - 1][j - 1];
			else if (j == 0)
				dp[i][j] = dp[i - 1][j + 1];
			else
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;

			if (j != 0)
				sum[i] = (sum[i] + dp[i][j]) % 1000000000;
		}
	}
	cout << sum[n];
	return 0;
}