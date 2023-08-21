#include<iostream>
#include<algorithm>
#include<climits>

using namespace std;

int n, m;
long long* min_tree;
long long* max_tree;
int unit, height, tree_size;

int getTreeIndex(int index) {
	return unit + index - 1;
}
void init() {
	unit = height = 1;
	while (unit < n) {
		unit *= 2;
		height++;
	}
	tree_size = (1 << height);
	min_tree = new long long[tree_size + 1];
	max_tree = new long long[tree_size + 1];
}

void input() {
	cin >> n >> m;
	long long a;
	init();
	for (int i = 0; i < n; i++) {
		cin >> a;
		min_tree[unit + i] = max_tree[unit + i] = a;
	}

	for (int i = (n + unit); i < tree_size; i++) {
		min_tree[i] = LONG_MAX;
	}
}

void build() {
	for (int i = unit - 1; i > 0; i--) {
		min_tree[i] = min(min_tree[i * 2], min_tree[i * 2 + 1]);
	}
	for (int i = unit - 1; i > 0; i--) {
		max_tree[i] = max(max_tree[i * 2], max_tree[i * 2 + 1]);
	}
}

long long get_min(int start, int end) {
	start = getTreeIndex(start);
	end = getTreeIndex(end);
	long long minimum = LONG_MAX;
	while (start <= end) {
		if (start % 2 == 1) {
			minimum = min(minimum, min_tree[start]);
			start++;
		}
		if (end % 2 == 0) {
			minimum = min(minimum, min_tree[end]);
			end--;
		}
		start /= 2;
		end /= 2;
	}
	return minimum;
}

long long get_max(int start, int end) {
	start = getTreeIndex(start);
	end = getTreeIndex(end);
	long long maximum = 0;
	while (start <= end) {
		if (start % 2 == 1) {
			maximum = max(maximum, max_tree[start]);
			start++;
		}
		if (end % 2 == 0) {
			maximum = max(maximum, max_tree[end]);
			end--;
		}
		start /= 2;
		end /= 2;
	}
	return maximum;
}

void solve() {
	int a, b;
	while (m--) {
		cin >> a >> b;
		cout << get_min(a, b) << " " << get_max(a, b) << "\n";
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	build();
	solve();

	return 0;
}
