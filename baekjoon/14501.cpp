#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int dp[15];

int main() {
	int n, t, p, m, res = 0;
	cin >> n;
	vector<pair<int, int>>v;
	for (int i = 0; i < n; i++) {
		cin >> t >> p;
		v.push_back(make_pair(t, p));
	}

	for (int i = 0; i < n; i++) {
		if ((i + v[i].first) <= n)
			dp[i] = v[i].second;

		m = 0;
		for (int j = 0; j < i; j++) {
			if (dp[j] > m && (v[j].first + j) <= i) {
				m = dp[j];
			}
		}
		dp[i] += m;
		res = max(res, dp[i]);
	}
	cout << res;
	return 0;
}