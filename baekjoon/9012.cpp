#include<iostream>
#include<stack>

using namespace std;

int main() {
	int t;
	string str;
	cin >> t;
	while (t--) {
		stack<char>s;
		bool res = true;
		cin >> str;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '(') {
				s.push(str[i]);
			}
			else {
				if (s.empty()) {
					res = false;
					break;
				}
				s.pop();
			}
		}
		if (res && s.empty())
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}