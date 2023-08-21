#include<iostream>
#include<algorithm>

using namespace std;

const int MAX = 1500001;
int n;
long long dp[MAX];
int t[MAX];
int p[MAX];

void input() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t[i] >> p[i];
	}
}

bool isAvail(int cur, int time) {
	return (cur + time - 1) <= n;
}

long long solve() {
	long long res = 0;
	int next;
	for (int i = n; i > 0; i--) {
		if (isAvail(i, t[i])) {
			dp[i] = p[i];
			next = (i + t[i]);
			if (next <= n) {
				dp[i] += dp[next];
			}
		}
		res = max(res, dp[i]);
		dp[i] = res;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	cout << solve();
	return 0;
}