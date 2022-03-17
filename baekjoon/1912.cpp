#include<iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	int num;
	int* dp = new int[n + 1];
	dp[0] = 0;
	int max = -1000;

	for (int i = 0; i < n; i++) {
		cin >> num;
		if (dp[i - 1] + num > num)
			dp[i] = dp[i - 1] + num;
		else
			dp[i] = num;
		if (dp[i] > max)
			max = dp[i];
	}
	cout << max;

	return 0;
}