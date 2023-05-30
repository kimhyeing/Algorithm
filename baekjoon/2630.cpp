#include<iostream>

using namespace std;

int n;
int arr[128][128];
int blue;
int white;

bool solve(int x1, int x2, int y1, int y2) {
	int first = arr[x1][y1];
	for (int i = x1; i <= x2; i++) {
		for (int j = y1; j <= y2; j++) {
			if (arr[i][j] != first)
				return false;
		}
	}
	if (first == 1) blue++;
	else white++;
	return true;
}

void divide(int x1, int x2, int y1, int y2) {
	if (!solve(x1, x2, y1, y2)) {
		int midx = (x1 + x2) / 2;
		int midy = (y1 + y2) / 2;
		divide(x1, midx, y1, midy);
		divide(x1, midx, midy + 1, y2);
		divide(midx + 1, x2, y1, midy);
		divide(midx + 1, x2, midy + 1, y2);
	}
}

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
}
int main() {
	input();
	divide(0, n - 1, 0, n - 1);
	cout << white << "\n" << blue;
	return 0;
}