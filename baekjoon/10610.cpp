#include<iostream>
#include<algorithm>

using namespace std;

int num[10];

int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	cin >> str;

	int sum = 0;
	bool isTensTimes = false;
	for (int i = 0; i < str.length(); i++) {
		sum += str[i] % 3;
		sum %= 3;
		num[(str[i] - '0')]++;
		if (str[i] == '0') isTensTimes = true;
	}

	if (sum == 0 && isTensTimes) {
		for (int i = 9; i >= 0; i--) {
			for (int j = 0; j < num[i]; j++) {
				cout << i;
			}
		}
	}
	else {
		cout << -1;
	}

	return 0;
}