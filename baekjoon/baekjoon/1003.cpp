#include<iostream>

using namespace std;

int dp[41];

int fibonacci(int n) {
	if (dp[n] != 0 || n == 0)
		return dp[n];

	return dp[n] = fibonacci(n - 1) + fibonacci(n - 2);
}
int main() {
	int t, n;
	cin >> t;
	dp[1] = 1;
	while (t--) {
		cin >> n;
		if (n == 0)
			cout << 1 << " " << dp[n] << "\n";
		else {
			fibonacci(n);
			cout << dp[n - 1] << " " << dp[n] << "\n";
		}
	}
	return 0;
}