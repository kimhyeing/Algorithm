#include<iostream>
#include<deque>
#include<string>

using namespace std;

int main() {
	deque<int>dq;

	int n, x;
	string str;
	cin >> n;
	while (n--) {
		cin >> str;
		if (str == "push_front") {
			cin >> x;
			dq.push_front(x);
		}
		else if (str == "push_back") {
			cin >> x;
			dq.push_back(x);
		}
		else if (str == "pop_front") {
			if (dq.empty()) {
				cout << "-1\n";
				continue;
			}
			cout << dq.front() << "\n";
			dq.pop_front();
		}
		else if (str == "pop_back") {
			if (dq.empty()) {
				cout << "-1\n";
				continue;
			}
			cout << dq.back() << "\n";
			dq.pop_back();
		}
		else if (str == "size") {
			cout << dq.size() << "\n";
		}
		else if (str == "empty") {
			cout << dq.empty() << "\n";
		}
		else if (str == "front") {
			if (dq.empty()) {
				cout << "-1\n";
				continue;
			}
			cout << dq.front() << "\n";
		}
		else {
			if (dq.empty()) {
				cout << "-1\n";
				continue;
			}
			cout << dq.back() << "\n";
		}
	}

	return 0;
}