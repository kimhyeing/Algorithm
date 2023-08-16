#include<iostream>
#include<string>
#include<unordered_set>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	string str;
	unordered_set<string>us;
	while (n--) {
		cin >> str;
		us.insert(str);
	}
	int res = 0;
	while (m--) {
		cin >> str;
		if (us.find(str) != us.end()) {
			res++;
		}
	}
	cout << res;
	return 0;
}