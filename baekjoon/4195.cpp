#include<iostream>
#include<unordered_map>

using namespace std;

struct value {
	string root;
	int number;
};

unordered_map<string, value>parent;

value find(string x) {
	if (parent[x].root == x) return parent[x];
	return parent[x] = find(parent[x].root);
}

int merge(string x, string y) {
	value v1 = find(x);
	value v2 = find(y);
	x = v1.root;
	y = v2.root;
	
	if (x == y) return v1.number;

	if (v1.number < v2.number) {
		parent[y].number += v1.number;
		parent[x].root = y;
		return parent[y].number;
	}
	else {
		parent[x].number += v2.number;
		parent[y].root = x;
		return parent[x].number;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, f;
	cin >> t;
	string s1, s2;
	while (t--) {
		cin >> f;
		for (int i = 0; i < f; i++) {
			cin >> s1 >> s2;
			if (parent.find(s1) == parent.end()) {
				parent.insert({ s1, {s1, 1} });
			}
			if (parent.find(s2) == parent.end()) {
				parent.insert({ s2, {s2, 1} });
			}
			cout << merge(s1, s2) << "\n";
		}
		parent.clear();
	}

	return 0;
}