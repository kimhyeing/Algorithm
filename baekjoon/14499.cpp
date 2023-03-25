#include<iostream>

using namespace std;

int arr[21][21];

#define E 1
#define W 2
#define N 3
#define S 4

int posx[4] = {0, 0, -1, 1};
int posy[4] = { 1,-1,0,0 };

int main() {
	int n, m, x, y, k, a;
	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	int dice[6] = { 0, };
	int bottom = 0, top = 5, newx = x, newy = y;
	int preBottom, newBottom;
	for (int i = 0; i < k; i++) {
		cin >> a;
		newx += posx[a - 1];
		newy += posy[a - 1];
		if (newx < 0 || newy < 0 || newx >= n || newy >= m) {
			newx -= posx[a - 1];
			newy -= posy[a - 1];
			continue;
		}

		preBottom = dice[bottom];
		newBottom = dice[a];
		if (arr[newx][newy] != 0) {
			newBottom = arr[newx][newy];
			arr[newx][newy] = 0;
		}
		else {
			arr[newx][newy] = newBottom;
		}

		if (a == E) {
			dice[bottom] = newBottom;
			dice[E] = dice[top];
			dice[top] = dice[W];
			dice[W] = preBottom;
		}
		else if (a == W) {
			dice[bottom] = newBottom;
			dice[W] = dice[top];
			dice[top] = dice[E];
			dice[E] = preBottom;
		}
		else if (a == N) {
			dice[bottom] = newBottom;
			dice[N] = dice[top];
			dice[top] = dice[S];
			dice[S] = preBottom;
		}
		else if (a == S) {
			dice[bottom] = newBottom;
			dice[S] = dice[top];
			dice[top] = dice[N];
			dice[N] = preBottom;
		}
		cout << dice[top] << "\n";
	}
	return 0;
}