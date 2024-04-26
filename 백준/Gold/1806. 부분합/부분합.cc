#include<iostream>

using namespace std;

int arr[100001];

int main() {
	int n, s;
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int start = 0, end = 0;
	int min_c = 100001;
	int partial_sum = 0;
	int len = 0;

	while (end <= n) {
		if (partial_sum < s) {
			partial_sum += arr[end++];
		}
		else {
			partial_sum -= arr[start++];
		}
		len = end - start;
		if (partial_sum >= s && len < min_c) {
			min_c = len;
		}
	}

	if (min_c == 100001)
		cout << 0;
	else
		cout << min_c;

	return 0;
}