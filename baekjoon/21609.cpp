#include<iostream>
#include<set>
#include<queue>
#include<cstring>
#include<algorithm>

using namespace std;

struct group {
	int r;
	int c;
	int b_size;
	int r_size;
};

struct comp {
	bool operator() (const group& g1, const group& g2) const {
		if (g1.b_size == g2.b_size) {
			if (g1.r_size == g2.r_size) {
				if (g1.r == g2.r) {
					return g1.c > g2.c;
				}
				return g1.r > g2.r;
			}
			return g1.r_size > g2.r_size;
		}
		return g1.b_size > g2.b_size;
	}
};

int n, m, score, b_num, r_num;
int left_block;
int arr[21][21];
int temp_arr[21][21];
bool visit[21][21];
int posx[4] = { 1,0,-1,0 };
int posy[4] = { 0,1,0,-1 };
int newx, newy;
group big;

void input() {
	cin >> n >> m;
	int a;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a;
			arr[i][j] = a;
			if (a > 0) {
				left_block++;
			}
		}
	}
}

void bfs(int x, int y, int color, bool remove) {
	bool visit_0[21][21] = { false, };
	queue<pair<int, int>>q;
	q.push(make_pair(x, y));
	int cur_x, cur_y;
	visit[x][y] = true;

	while (!q.empty()) {
		cur_x = q.front().first;
		cur_y = q.front().second;
		q.pop();
		if (remove) {
			arr[cur_x][cur_y] = -2;
		}

		for (int i = 0; i < 4; i++) {
			newx = cur_x + posx[i];
			newy = cur_y + posy[i];
			if (newx < 0 || newy < 0 || newx >= n || newy >= n || arr[newx][newy] <= -1)
				continue;

			if (arr[newx][newy] == 0 && !visit_0[newx][newy]) {
				visit_0[newx][newy] = true;
				q.push(make_pair(newx, newy));
				r_num++;
			}
			else if (arr[newx][newy] == color && !visit[newx][newy]) {
				visit[newx][newy] = true;
				q.push(make_pair(newx, newy));
				b_num++;
			}
		}
	}
}

void search() {
	left_block = 0;
	memset(visit, false, sizeof(visit));
	set<group, comp>set_group;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] > 0 && !visit[i][j]) {
				b_num = 1;
				r_num = 0;
				bfs(i, j, arr[i][j], false);
				if ((b_num + r_num) >= 2) {
					set_group.insert(group{ i,j,(b_num + r_num),r_num });
				}
			}
		}
	}
	left_block = set_group.size();
	if (left_block > 0) {
		big = *set_group.begin();
		memset(visit, false, sizeof(visit));
		bfs(big.r, big.c, arr[big.r][big.c], true);

		score += (big.b_size * big.b_size);
	}
}

void gravity() {
	int temp_r, temp_color;
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] >= 0) {
				temp_r = i;
				temp_color = arr[i][j];
				while (true) {
					if ((temp_r + 1) >= n || arr[(temp_r + 1)][j] >= -1) {
						break;
					}
					temp_r++;
				}
				arr[i][j] = -2;
				arr[temp_r][j] = temp_color;
			}
		}
	}
}

void move() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			temp_arr[i][j] = arr[j][n - 1 - i];
		}
	}

	copy(&temp_arr[0][0], &temp_arr[n][n], &arr[0][0]);
}

int main() {
	input();
	while (left_block != 0) {
		search();
		if (left_block == 0)
			break;
		gravity();
		move();
		gravity();
	}
	cout << score;
	return 0;
}