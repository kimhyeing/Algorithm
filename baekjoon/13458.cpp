#include<iostream>
#include<vector>

using namespace std;

int main() {
	int n, a, b, c;
	vector<int>v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}
	cin >> b >> c;
	
	long long int res = n;
	int temp;
	for (int i = 0; i < n; i++) {
		temp = v[i] - b;
		if (temp > 0) {
			res += (temp / c);
			if (temp % c > 0) res++;
		}
	}
	cout << res;

	return 0;
}