#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<algorithm>

using namespace std;

string result = "YES";

class Trie {
public:
	bool finish;
	Trie* next[10];

	Trie() {
		finish = false;
		memset(next, 0, sizeof(next));
	}

	void insert(const char* key) {
		if (*key == '\0')
			finish = true;
		else {
			if (finish) {
				result = "NO";
			}
			int curr = *key - '0';
			if (next[curr] == NULL)
				next[curr] = new Trie();
			next[curr]->insert(key + 1);
		}
	}

	Trie* find(const char* key) {
		if (*key == '\0') return this;
		int curr = *key - 'A';
		if (next[curr] == NULL) return NULL;
		return next[curr]->find(key + 1);
	}
};

int main() {
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		Trie* t = new Trie();
		vector<string>v;
		string s;
		for (int i = 0; i < n; i++) {
			cin >> s;
			v.push_back(s);
		}
		sort(v.begin(), v.end());
		for (int i = 0; i < n; i++) {
			const char* c = v[i].c_str();
			t->insert(c);
		}
		cout << result << "\n";
		result = "YES";
	}

}