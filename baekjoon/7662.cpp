#include<iostream>
#include<set>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t, k, n;
	char ins;
	cin >> t;
	while (t--) {
		multiset<int> ms;
		cin >> k;
		while (k--) {
			cin >> ins >> n;
			if (ins == 'I') {
				ms.insert(n);
			}
			else {
				if (ms.empty()) continue;

				if (n == 1) {
					ms.erase(--ms.end());
				}
				else {
					ms.erase(ms.begin());
				}
			}
		}

		if (ms.empty()) cout << "EMPTY\n";
		else {
			cout << *(--ms.end()) << " " << *ms.begin() << "\n";
		}
	}

	return 0;
}