#include<iostream>

using namespace std;

long long int dp[91];

long long int fibo(long long int n) {
	if (n <= 1) return n;
	if (dp[n] != 0) return dp[n];
	return dp[n] = fibo(n - 1) + fibo(n - 2);
}

int main() {
	int n;
	cin >> n;
	cout << fibo(n);

	return 0;
}