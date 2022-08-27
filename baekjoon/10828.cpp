#include<iostream>
#include<stack>

using namespace std;

int main() {
	int n, num;
	string str;
	stack<int>s;
	cin >> n;
	while (n--) {
		cin >> str;
		if (str == "push") {
			cin >> num;
			s.push(num);
		}
		else if (str == "pop") {
			if (s.empty()) cout << "-1\n";
			else {
				cout << s.top() << "\n";
				s.pop();
			}
		}
		else if (str == "size")
			cout << s.size() << "\n";
		else if (str == "empty")
			cout << s.empty() << "\n";
		else if (str == "top") {
			if (s.empty()) cout << "-1\n";
			else cout << s.top() << "\n";
		}
	}

	return 0;
}