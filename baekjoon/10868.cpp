#include<iostream>
#include<climits>
#include<algorithm>

using namespace std;

int n, m;
int unit, height, tree_size;
long long* tree;

int getTreeIndex(int index) {
	return unit + index - 1;
}

void init() {
	height = unit = 1;
	while (unit < n) {
		unit *= 2;
		height++;
	}
	tree_size = (1 << height);
	tree = new long long[tree_size + 1];
}

void input() {
	cin >> n >> m;
	init();
	for (int i = 0; i < n; i++) {
		cin >> tree[unit + i];
	}
	for (int i = unit + n; i < tree_size; i++) {
		tree[i] = LONG_MAX;
	}
}


void build() {
	for (int i = unit - 1; i > 0; i--) {
		tree[i] = min(tree[i * 2], tree[i * 2 + 1]);
	}
}

long long query(int start, int end) {
	start = getTreeIndex(start);
	end = getTreeIndex(end);
	long long minimum = LONG_MAX;
	while (start <= end) {
		if (start % 2 == 1) {
			minimum = min(minimum, tree[start]);
			start++;
		}
		if (end % 2 == 0) {
			minimum = min(minimum, tree[end]);
			end--;
		}
		start /= 2;
		end /= 2;
	}
	return minimum;
}

void solve() {
	int a, b;
	while (m--) {
		cin >> a >> b;
		cout << query(a, b) << "\n";
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