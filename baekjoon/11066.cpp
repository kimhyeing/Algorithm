#include<iostream>

using namespace std;

int dp[500][500];
int sum[500][500];
int arr[500];
int t, k;

void input() {
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> arr[i];
		dp[i][i] = arr[i];
		sum[i][i] = 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	int end, temp_dp, temp_sum;

	while (t--) {
		input();

		for (int gap = 1; gap < k; gap++) {
			for (int start = 0; start < (k - gap); start++) {
				end = start + gap;
				
				for (int middle = start; middle < end; middle++) {
					temp_dp = dp[start][middle] + dp[middle + 1][end];
					if (middle == start) {
						dp[start][end] = temp_dp;
						sum[start][end] = dp[start][end] + sum[start][middle] + sum[middle + 1][end];
					}
					else {
						if (sum[start][end] > (temp_sum = (temp_dp + sum[start][middle] + sum[middle + 1][end]))) {
							dp[start][end] = temp_dp;
							sum[start][end] = temp_sum;
						}
					}
				}
			}
		}

		cout << sum[0][k - 1] << "\n";
	}
	return 0;
}