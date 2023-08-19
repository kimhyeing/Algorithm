#include<iostream>
#include<vector>

using namespace std;

int parent[51];
bool knowGroup[51];

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

bool isTrue(int x) {
	x = find(x);
	return (x == 0);
}

void setTrue(int x) {
	parent[x] = 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, tn, a, pn;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	cin >> tn;
	while (tn--) {
		cin >> a;
		parent[a] = 0;
	}

	vector<int>v[50];
	for (int i = 0; i < m; i++) {
		cin >> pn;
		while (pn--) {
			cin >> a;
			v[i].push_back(a);
		}
	}
	
	for (int t = 0; t < m; t++) {
		for (int i = 0; i < m; i++) {
			if (!knowGroup[i]) {
				for (int j = 0; j < v[i].size(); j++) {
					if (isTrue(v[i][j])) {
						knowGroup[i] = true;
						break;
					}
				}
				if (knowGroup[i]) {
					for (int j = 0; j < v[i].size(); j++) {
						setTrue(v[i][j]);
					}
				}
			}
		}
	}

	int res = 0;
	for (int i = 0; i < m; i++) {
		if (!knowGroup[i]) {
			res++;
		}
	}
	cout << res;

	return 0;
}