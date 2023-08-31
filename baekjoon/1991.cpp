#include<iostream>

using namespace std;

char tree[26][2];

void preorder(int idx) {
	char node = 'A' + idx;
	cout << node;
	if (tree[idx][0] != '.') preorder(tree[idx][0] - 'A');
	if (tree[idx][1] != '.') preorder(tree[idx][1] - 'A');
}

void inorder(int idx) {
	if (tree[idx][0] != '.') inorder(tree[idx][0] - 'A');
	char node = 'A' + idx;
	cout << node;
	if (tree[idx][1] != '.') inorder(tree[idx][1] - 'A');
}

void postorder(int idx) {
	if (tree[idx][0] != '.') postorder(tree[idx][0] - 'A');
	if (tree[idx][1] != '.') postorder(tree[idx][1] - 'A');
	char node = 'A' + idx;
	cout << node;
}

int main() {
	int n;
	char node, c1, c2;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> node >> c1 >> c2;
		tree[node - 'A'][0] = c1;
		tree[node - 'A'][1] = c2;
	}
	preorder(0);
	cout << "\n";
	inorder(0);
	cout << "\n";
	postorder(0);
	return 0;
}