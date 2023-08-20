#include<iostream>
#include<algorithm>

using namespace std;

int arr[1001];
int dp[1001];

int main() {
	int n;
	cin >> n;
	
	int max_dp, res = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		max_dp = -1;
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[i]) {
				max_dp = max(max_dp, dp[j]);
			}
		}
		dp[i] = max_dp + 1;
		res = max(dp[i], res);
	}

	cout << res + 1;
	return 0;
}