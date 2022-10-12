#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int n, w;
	vector<int>v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> w;
		v.push_back(w);
	}
	sort(v.rbegin(), v.rend());

	int res = 0, temp;
	for (int i = 0; i < n; i++) {
		temp = v[i] * (i + 1);
		res = max(res, temp);
	}
	cout << res;

	return 0;
}