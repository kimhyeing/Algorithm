#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int main() {
	int n, h;
	stack<pair<int, int>>s;
	vector<int>v;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> h;
		v.push_back(h);
	}

	for (int i = 0; i < n; i++) {
		while (!s.empty() && s.top().first < v[i]) {
			s.pop();
		}

		if (s.empty()) {
			cout << 0;
		}
		else {
			cout << s.top().second;
		}

		s.push(make_pair(v[i], i + 1));
		cout << " ";
	}
	return 0;
}