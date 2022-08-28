#include<iostream>
#include<stack>

using namespace std;

int main() {
	string str;
	while (true) {
		getline(cin, str);
		if (str == ".") break;
		stack<char>s;
		bool res = true;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '(')
				s.push('(');
			else if (str[i] == ')') {
				if (s.empty() || s.top() != '(') {
					res = false;
					break;
				}
				s.pop();
			}
			else if (str[i] == '[')
				s.push('[');
			else if (str[i] == ']') {
				if (s.empty() || s.top() != '[') {
					res = false;
					break;
				}
				s.pop();
			}
		}
		if (res && s.empty())
			cout << "yes\n";
		else
			cout << "no\n";
	}
	return 0;
}