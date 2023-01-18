#include<iostream>
#include<algorithm>

using namespace std;

int arr[10001];
int k, n;
long long int result = 0, num = 0;

long long int solve(int maxK) {
	long long int left = 0, right = maxK, mid = 0;
	
	while (right >= left) {
		if (right == 1) left = right;

		mid = (right + left) / 2;
		
		for (int i = 0; i < k; i++) {
			num += (arr[i] / mid);
		}
		if (num < n) {
			right = mid - 1;
		}
		else {
			if (result < mid)
				result = mid;
			
			left = mid + 1;
		}
		num = 0;
	}

	return result;
}

int main() {
	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + k);
	cout << solve(arr[k-1]);

	return 0;
}