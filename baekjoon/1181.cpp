#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

bool compareDic(string a, string b, int i) {
	if (int(a[i]) == int(b[i])) {
		return compareDic(a, b, i + 1);
	}
	return (int(a[i]) < int(b[i]));
}

bool compare(string a, string b) {
	if (a.length() == b.length()) {
		return compareDic(a, b, 0);
	}
	return a.length() < b.length();
}

int main() {
	int n;
	cin >> n;
	string s;
	vector<string>v;

	for (int i = 0; i < n; i++) {
		cin >> s;
		v.push_back(s);
	}

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	n = v.size();
	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < n; i++) {
		cout << v[i] << "\n";
	}

	return 0;
}