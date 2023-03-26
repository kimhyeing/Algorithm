#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int arr[12];
vector<char>cal;
int n, c, min_res = INT32_MAX, max_res = INT32_MIN, res;
bool used[11];

void calculate(int num, int temp, bool _used[11]) {
	if (num == n - 1) {
		min_res = min(min_res, temp);
		max_res = max(max_res, temp);
		return;
	}

	for (int i = 0; i < n - 1; i++) {
		if (_used[i]) continue;
		
		res = temp;
		if (cal[i] == '+') res += arr[num + 1];
		else if (cal[i] == '-') res -= arr[num + 1];
		else if (cal[i] == '*') res *= arr[num + 1];
		else res /= arr[num + 1];

		bool temp_used[11];
		copy(_used, _used + n - 1, temp_used);
		temp_used[i] = true;
		calculate(num + 1, res, temp_used);
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < 4; i++) {
		cin >> c;
		for (int j = 0; j < c; j++) {
			if (i == 0) cal.push_back('+');
			else if (i == 1) cal.push_back('-');
			else if (i == 2) cal.push_back('*');
			else cal.push_back('/');
		}
	}
	calculate(0, arr[0], used);
	cout << max_res << "\n" << min_res;
	return 0;
}