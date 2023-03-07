#include<iostream>
#include<set>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t, k, n;
	int max_num, min_num;
	char ins;
	cin >> t;
	while (t--) {
		multiset<int> min_ms;
		multiset<int, greater<int>> max_ms;
		cin >> k;
		while (k--) {
			cin >> ins >> n;
			if (ins == 'I') {
				min_ms.insert(n);
				max_ms.insert(n);
			}
			else {
				if (min_ms.empty()) continue;

				if (n == 1) {
					max_num = *max_ms.begin();
					min_ms.erase(min_ms.lower_bound(max_num));
					max_ms.erase(max_ms.begin());
				}
				else {
					min_num = *min_ms.begin();
					min_ms.erase(min_ms.begin());
					max_ms.erase(max_ms.lower_bound(min_num));
				}
			}
		}

		if (min_ms.empty()) cout << "EMPTY\n";
		else {
			cout << *max_ms.begin() << " " << *min_ms.begin() << "\n";
		}
	}

	return 0;
}