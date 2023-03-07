#include<iostream>
#include<set>
#include<map>
#include<vector>

using namespace std;

int main() {
	int n, k, m, v, c;
	cin >> n >> k;

	multimap<int, int, greater<int>>jewel;
	multiset<int>bag;

	for (int i = 0; i < n; i++) {
		cin >> m >> v;
		jewel.insert(make_pair(v, m));
	}

	for (int i = 0; i < k; i++) {
		cin >> c;
		bag.insert(c);
	}

	long long int res = 0;
	while (!jewel.empty() && !bag.empty()) {
		v = (*jewel.begin()).first;
		m = (*jewel.begin()).second;

		jewel.erase(jewel.begin());
		if (bag.lower_bound(m) != bag.end()) {
			bag.erase(bag.lower_bound(m));
			res += v;
		}
	}
	cout << res;
	return 0;
}