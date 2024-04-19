#include<iostream>

using namespace std;

int dp[1001];

int op(int n) {
	if (dp[n] != 0)
		return dp[n];
	return dp[n] = (op(n - 1) + op(n - 2)) % 10007;
}

int main() {
	int n;
	cin >> n;
	dp[1] = 1;
	dp[2] = 2;

	cout << op(n);
	return 0;
}