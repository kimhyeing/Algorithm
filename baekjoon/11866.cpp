#include<iostream>
#include<queue>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	queue<int>q;
	for (int i = 0; i < n; i++) {
		q.push(i + 1);
	}

	int repeat = 0;
	cout << "<";
	while (!q.empty()) {
		repeat++;
		if (repeat % k == 0) {
			cout << q.front();
			q.pop();
			if (!q.empty()) cout << ", ";
		}
		else {
			q.push(q.front());
			q.pop();
		}
	}
	cout << ">";

	return 0;
}