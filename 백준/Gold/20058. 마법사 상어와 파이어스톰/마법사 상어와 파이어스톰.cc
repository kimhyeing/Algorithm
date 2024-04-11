#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = (1 << 6);
int N, Q, len, result;
int arr[MAX+1][MAX+1];
int copy_arr[MAX+1][MAX+1];
bool visited[MAX+1][MAX+1];
int L[1000];
int dirx[4] = { -1,0,1,0 };
int diry[4] = { 0,1,0,-1 };

void input() {
	cin >> N >> Q;
	len = (1 << N);
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < Q; i++) {
		cin >> L[i];
	}
}

void lotation(int x, int y, int area) {
	for (int i = 0; i < area; i++) {
		for (int j = 0; j < area; j++) {
			copy_arr[x+i][y+j] = arr[x+area - 1 - j][y+i];
		}
	}
}

void melting() {
	int ice, newx, newy;
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			ice = 0;
			if (copy_arr[i][j] == 0) continue;
			for (int d = 0; d < 4; d++) {
				newx = i + dirx[d];
				newy = j + diry[d];
				if (newx < 0 || newy < 0 || newx >= len || newy >= len) continue;
				if (copy_arr[newx][newy] > 0) ice++;
			}

			if (ice < 3) {
				arr[i][j]--;
			}
		}
	}
}

void solve() {
	int area;
	for (int i = 0; i < Q; i++) {
		area = (1 << L[i]);
		// lotation
		for (int x = 0; x < len; x += area) {
			for (int y = 0; y < len; y += area) {
				lotation(x, y, area);
			}
		}
		copy(&copy_arr[0][0], &copy_arr[len - 1][len], &arr[0][0]);

		// melting
		melting();
	}
}

int total() {
	int result = 0;
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			result += arr[i][j];
		}
	}
	return result;
}

int cnt, max_area;
void dfs(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int newx = x + dirx[i];
		int newy = y + diry[i];
		if (newx < 0 || newy < 0 || newx >= len || newy >= len) continue;
		if (visited[newx][newy] || !arr[newx][newy]) continue;
		visited[newx][newy] = true;
		cnt++;
		dfs(newx, newy);
	}
}

void maxArea() {
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			if (!visited[i][j] && arr[i][j]) {
				cnt = 1;
				visited[i][j] = true;
				dfs(i, j);
				max_area = max(max_area, cnt);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	solve();
	maxArea();
	cout << total() << "\n" << max_area;
	return 0;
}