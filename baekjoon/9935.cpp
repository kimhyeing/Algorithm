#include<iostream>
#include<string>

using namespace std;

int main() {
	string str, bomb;
	cin >> str >> bomb;
	string temp;
	bool ex;

	for (int i = 0; i < str.size(); i++) {
		ex = false;
		temp.push_back(str[i]);

		if (temp[temp.size() - 1] == bomb[bomb.size() - 1]) {
			ex = true;
			for (int j = 1; j < bomb.size(); j++) {
				if (temp[temp.size() - 1 - j] != bomb[bomb.size() - 1 - j]) {
					ex = false;
					break;
				}
			}
		}

		if (ex) {
			for (int j = 0; j < bomb.size(); j++) {
				temp.pop_back();
			}
		}
	}

	if (temp.empty()) {
		cout << "FRULA";
	}
	else {
		cout << temp;
	}
	return 0;
}