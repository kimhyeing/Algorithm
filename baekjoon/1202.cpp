#include<iostream>
#include<set>
#include<map>

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

		auto upper = bag.upper_bound(m);
		auto lower = bag.lower_bound(m);

		jewel.erase(jewel.begin());
		if (lower != bag.end()) {
			bag.erase(lower);
			res += v;
		}	
		else if (upper != bag.end()) {
			bag.erase(upper);
			res += v;	
		}
	}
	cout << res;
	return 0;
}