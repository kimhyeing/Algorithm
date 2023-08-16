#include<iostream>
#include<string>
#include<unordered_map>
#include<set>

using namespace std;

int main() {
	int t, n;
	cin >> t;
	string s1, s2;
	
	while (t--) {
		unordered_map<string, int>um;
		set<string>wear;
		cin >> n;
		while (n--) {
			cin >> s1 >> s2;
			auto iter = um.find(s2);
			if (iter == um.end()) {
				wear.insert(s2);
				um.insert(make_pair(s2, 2));
			}
			else {
				iter->second += 1;
			}
		}
		int res = 1;
		for (auto iter : wear) {
			res *= um.find(iter)->second;
		}
		cout << res - 1 << "\n";
	}

	return 0;
}