#include<iostream>
#include<string>
#include<vector>
#include<cmath>

using namespace std;

int main() {
	string str;
	vector<int>num;
	vector<char>oper;
	cin >> str;

	int n[5];
	int res = 0, index = 0;
	for (int i = 0; i <= str.length(); i++) {
		if (i == str.length() || str[i] == '+' || str[i] == '-') {
			for (int j = 0; j < index; j++) {
				res += (n[j] * pow(10, index - j - 1));
			}
			num.push_back(res);
			if(i < str.length())
				oper.push_back(str[i]);
			res = index = 0;
		}
		else {
			n[index++] = str[i] - '0';
		}
	}

	bool negative = false;
	for (int i = 0; i < oper.size(); i++) {
		if (oper[i] == '-')
			negative = true;

		if (negative && oper[i] == '+')
			oper[i] = '-';
	}

	int result = num[0];
	for (int i = 0; i < oper.size(); i++) {
		if (oper[i] == '+')
			result += num[i + 1];
		else
			result -= num[i + 1];
	}
	cout << result;
	return 0;
}