#include<iostream>
#include<queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<int, vector<int>, greater<int>>pq;
	int n, x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		pq.push(x);
	}

	int res = 0;
	int a, b = 0;
	for (int i = 0; i < n; i++) {
		a = pq.top();
		pq.pop();
		if (!pq.empty()) {
			b = pq.top();
			pq.pop();
			pq.push(a + b);
			res += (a + b);
		}
	}
	cout << res;
	return 0;
}