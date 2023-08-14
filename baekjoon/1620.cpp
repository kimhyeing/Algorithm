#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<string>v;
	unordered_map<string, int>pm;
	string str;
	for(int i=1;i<=n;i++) {
		cin >> str;
		v.push_back(str);
		pm.insert({ str,i });
	}
	while (m--) {
		cin >> str;
		if (str[0] > '0' && str[0] <= '9') {
			cout << v[stoi(str) - 1] << "\n";
		}
		else {
			cout << pm.find(str)->second << "\n";
		}
	}
	return 0;
}