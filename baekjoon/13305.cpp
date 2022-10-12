#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int n, l, w;
	vector<long long int>vl;
	vector<long long int>vw;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> l;
		vl.push_back(l);
	}
	for (int i = 0; i < n; i++) {
		cin >> w;
		vw.push_back(w);
	}
	long long int res = vw[0] * vl[0], temp_w = vw[0];
	for (int i = 1; i < n - 1; i++) {
		temp_w = min(temp_w, vw[i]);
		res += temp_w * vl[i];
	}
	cout << res;
	return 0;
}