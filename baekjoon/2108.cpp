#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

bool compare(pair<int, int>a, pair<int, int>b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second > b.second;
}

int main() {
	int n, a, median, mode, range;
	double mean = 0;
	cin >> n;
	vector<pair<int, int>>v;
	for (int i = 0; i < n; i++) {
		cin >> a;
		mean += a;
		v.push_back(make_pair(a, 1));
	}
	mean /= n;
	mean = (int)round(mean);

	sort(v.begin(), v.end());
	median = v[(n - 1) / 2].first;
	range = v[n - 1].first - v[0].first;

	int index = -1;
	for (int i = 0; i < n; i++) {
		if (i < n - 1 && v[i] == v[i + 1]) {
			if (index == -1) {
				index = i;
			}
			v[index].second += 1;
		}
		else {
			index = -1;
		}
	}
	sort(v.begin(), v.end(), compare);
	if (n > 1 && v[0].second == v[1].second) {
		mode = v[1].first;
	}
	else {
		mode = v[0].first;
	}

	cout << mean << "\n" << median << "\n" << mode << "\n" << range;

	return 0;
}