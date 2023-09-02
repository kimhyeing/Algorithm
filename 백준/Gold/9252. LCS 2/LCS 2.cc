#include<iostream>
#include<string>
#include<algorithm>
#include<stack>

using namespace std;

int dp[1001][1001];

int main() {
	string a, b;
	cin >> b >> a;
	
	for (int i = 1; i <= a.size(); i++) {
		for (int j = 1; j <= b.size(); j++) {
			if (a[i-1] != b[j-1]) {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
			else {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
		}
	}
	cout << dp[a.size()][b.size()]<<"\n";

	int i = a.size(), j = b.size();
	stack<char>st;
	while (dp[i][j] != 0) {
		if (dp[i][j] == dp[i][j - 1])
			j--;
		else if (dp[i][j] == dp[i - 1][j])
			i--;
		else if (dp[i][j] - 1 == dp[i - 1][j - 1]) {
			st.push(a[i - 1]);
			i--;
			j--;
		}
	}

	int len = st.size();
	for (int i = 0; i < len; i++) {
		cout << st.top();
		st.pop();
	}

	return 0;
}