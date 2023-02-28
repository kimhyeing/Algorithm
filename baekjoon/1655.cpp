#include<iostream>
#include<queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<int>small;
	priority_queue<int, vector<int>, greater<int>>big;
	int n, x, mid, diff, temp;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x;
		if (i == 0) mid = x;
		else {
			if (x < mid) {
				small.push(x);
			}
			else {
				big.push(x);
			}

			diff = small.size() - big.size();
			if (diff > 0) {
				temp = mid;
				mid = small.top();
				small.pop();
				big.push(temp);
			}
			else if (diff < -1) {
				temp = mid;
				mid = big.top();
				big.pop();
				small.push(temp);
			}
		}
		cout << mid << "\n";
	}

	return 0;
}