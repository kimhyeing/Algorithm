#include<iostream>
#include<vector>

using namespace std;

vector<pair<int, int>>v[10001];
int visit[10001];
int last;
int result;

void dfs(int n, int len) {
	visit[n] = 1;
	if (len > result) {
		result = len;
		last = n;
	}
	for (int i = 0; i < v[n].size(); i++) {
		int node = v[n][i].first;
		if (visit[node] == 0)
			dfs(node, len + v[n][i].second);
	}
}

int main() {
	int n;
	cin >> n;
	int a, b, c;

	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b >> c;
		v[a].push_back(make_pair(b, c));
		v[b].push_back(make_pair(a, c));
	}

	dfs(1, 0);
	fill_n(visit, n+1, 0);
	result = 0;
	dfs(last, 0);
	cout << result;
	return 0;
}