#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, score;
bool visited[20][20];
bool rainbow_visited[20][20];
int arr[20][20];
int copy_arr[20][20];
int dirx[4] = { -1,0,1,0 };
int diry[4] = { 0,1,0,-1 };
const int RAINBOW = 0;
const int BLACK = -1;
const int EMPTY = -2;
bool isEnd;

struct Group {
	int color;
	int size;
	int rainbow;
	int x;
	int y;
};

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
}

struct cmp {
	bool operator() (Group& a, Group& b) {
		if (a.size == b.size) {
			if (a.rainbow == b.rainbow) {
				if (a.x == b.x)
					return a.y < b.y;
				return a.x < b.x;
			}
			return a.rainbow < b.rainbow;
		}
		return a.size < b.size;
	}
};

priority_queue<Group, vector<Group>, cmp>pq;

void bfs(int x, int y, int color) {
	fill(&rainbow_visited[0][0], &rainbow_visited[n - 1][n], false);
	visited[x][y] = true;
	queue<pair<int, int>>q;
	int max_size = 1, max_rainbow = 0, curx, cury, newx, newy;
	
	q.push(make_pair(x,y));
	while (!q.empty()) {
		curx = q.front().first;
		cury = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			newx = curx + dirx[i];
			newy = cury + diry[i];
			if (newx < 0 || newy < 0 || newx >= n || newy >= n) continue;
			if (arr[newx][newy] != RAINBOW && arr[newx][newy] != color) continue;
			if (visited[newx][newy] || rainbow_visited[newx][newy]) continue;


			if (arr[newx][newy] == RAINBOW) {
				max_size++; max_rainbow++;
				rainbow_visited[newx][newy] = true;
			}
			else {
				max_size++;
				visited[newx][newy] = true;
			}

			q.push(make_pair(newx, newy));
		}
	}

	if ((max_size - max_rainbow) >= 1 && max_size >= 2) {
		Group g = { color, max_size, max_rainbow, x, y };
		pq.push(g);
	}
}

void blockDelete(Group g) {
	score += (g.size * g.size);
	int x = g.x, y = g.y, newx, newy;
	int color = arr[x][y];
	arr[x][y] = EMPTY;
	queue<pair<int, int>>q;
	q.push(make_pair(x,y));
	bool temp_visited[20][20];
	fill (&temp_visited[0][0], &temp_visited[n - 1][n], false);
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			newx = x + dirx[i];
			newy = y + diry[i];
			if (newx < 0 || newy < 0 || newx >= n || newy >= n) continue;
			if (arr[newx][newy] != RAINBOW && arr[newx][newy] != color) continue;
			if (temp_visited[newx][newy]) continue;
			temp_visited[newx][newy] = true;
			arr[newx][newy] = EMPTY;

			q.push(make_pair(newx, newy));
		}
	}
}

void gravity() {
	int down = 2, up = 0;
	int x, y;
	for (int i = n-2; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] < 0) continue;
			x = i; y = j;
			while (true) {
				x += dirx[down];
				y += diry[down];
				if (x == n || arr[x][y] != -2) {
					x += dirx[up];
					y += diry[up];
					break;
				}
			}
			if (x != i || y != j) {
				swap(arr[x][y], arr[i][j]);
			}
		}
	}
}

void lotation() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			copy_arr[i][j] = arr[j][n - 1 - i];
		}
	}
	copy(&copy_arr[0][0], &copy_arr[n - 1][n], &arr[0][0]);
}

void solve() {
	fill(&visited[0][0], &visited[n - 1][n], false);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] > 0 && !visited[i][j]) {
				bfs(i, j, arr[i][j]);
			}
		}
	}
	if (pq.empty()) {
		isEnd = true;
		return;
	}

	blockDelete(pq.top());
	while (!pq.empty()) pq.pop();

	gravity();

	lotation();

	gravity();
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	while (!isEnd) {
		solve();
	}
	cout << score;
	return 0;
}