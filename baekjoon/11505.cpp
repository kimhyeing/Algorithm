#include<iostream>

using namespace std;

const int MAX = 1000000007;
int tree_size;
int n, m, k, unit, height;
long long* tree;

int getTreeIndex(int index) {
	return index + unit - 1;
}

void init() {
	height = unit = 1;
	while (unit < n) {
		unit *= 2;
		height++;
	}
	tree_size = (1 << height);
	tree = new long long[tree_size];
}

void input() {
	cin >> n >> m >> k;
	init();
	for (int i = 0; i < n; i++) {
		cin >> tree[unit + i];
	}
	for (int i = unit + n; i < tree_size; i++) {
		tree[i] = 1;
	}
}

void build() {
	for (int i = unit - 1; i > 0; i--) {
		tree[i] = (tree[i * 2] * tree[i * 2 + 1]) % MAX;
	}
}

void update(int index, int value) {
	index = getTreeIndex(index);
	tree[index] = value;
	while (index > 1) {
		if (index % 2 == 1) {
			index--;
		}
		tree[index / 2] = (tree[index] * tree[index + 1]) % MAX;
		index /= 2;
	}
}

int query(int start, int end) {
	int mul = 1;
	start = getTreeIndex(start);
	end = getTreeIndex(end);

	while (start <= end) {
		if (start % 2 == 1) {
			mul = (mul * tree[start]) % MAX;
			start++;
		}
		if (end % 2 == 0) {
			mul = (mul * tree[end]) % MAX;
			end--;
		}
		start /= 2;
		end /= 2;
	}
	return mul;
}

void solve() {
	int a, b, c;
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

	input();
	build();
	solve();

	return 0;
}