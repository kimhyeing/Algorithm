#include<iostream>

using namespace std;

const int MAX = 1e6 + 1;
int n, m, k, unit;
long long tree[MAX<<2];

void setUnit() {
	unit = 1;
	while (unit < n) {
		unit <<= 1;
	}
}

void input() {
	for (int i = 0; i < n; i++) {
		cin >> tree[unit + i];
	}
}

void build() {
	for (int i = unit - 1; i > 0; i--) {
		tree[i] = tree[i << 1] + tree[(i << 1) + 1];
	}
}

int getTreeIndex(int num) {
	return num + unit - 1;
}

void update(int index, long long value) {
	index = getTreeIndex(index);
	long long gap = value - tree[index];
	while(index > 0) {
		tree[index] += gap;
		index >>= 1;
	}
}

long long query(int start, int end) {
	long long sum = 0;
	start = getTreeIndex(start);
	end = getTreeIndex(end);

	while (start <= end) {
		if (start % 2 == 1) {
			sum += tree[start];
			start++;
		}
		if (end % 2 == 0) {
			sum += tree[end];
			end--;
		}
		start >>= 1;
		end >>= 1;
	}
	return sum;
}

void solve() {
	int a, b;
	long long c;
	m += k;
	while (m--) {
		cin >> a >> b >> c;
		if (a == 1) {
			update(b, c);
		}
		else {
			cout << query(b, c) << "\n";
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k;
	setUnit();
	input();
	build();
	solve();
	return 0;
}