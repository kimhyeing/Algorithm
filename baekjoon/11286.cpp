#include<iostream>
#include<cmath>
#include<queue>

using namespace std;

struct cmp {
	bool operator()(int a, int b) {
		if (abs(a) == abs(b)) {
			return a > b;
		}
		return abs(a) > abs(b);
	}
};
bool compare(int a, int b) {
	return a < b;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, x;
	cin >> n;
	priority_queue<int, vector<int>, cmp>pq;
	while (n--) {
		cin >> x;
		if (x == 0) {
			if (pq.empty())cout << 0 << "\n";
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else {
			pq.push(x);
		}
	}

	return 0;
}