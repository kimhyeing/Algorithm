#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool compare(pair<int,int>a, pair<int,int>b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

int main() {
	int n, s, e;
	vector<pair<int, int>>v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s >> e;
		v.push_back(make_pair(s, e));
	}
	sort(v.begin(), v.end(), compare);

	int count = 1;
	e = v[0].second;
	for (int i = 1; i < n; i++) {
		if (v[i].first >= e) {
			count++;
			e = v[i].second;
		}
	}
	cout << count;
	return 0;
}