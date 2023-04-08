#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int n, m, k;
int arr[25][25];
int bottom = 3;
int dice[6] = { 2,1,5,6,4,3 };
int posx[4] = { 0,1,0,-1 };
int posy[4] = { 1,0,-1,0 };
int d = 0, dx, dy;
int bottom_num = 6, b_num;

void input() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}
	dx = dy = 1;
}

int bfs(int x, int y) {
	bool visit[25][25] = { false, };
	queue<pair<int, int> >q;
	q.push(make_pair(x, y));
	int curx, cury, newx, newy;
	visit[x][y] = true;
	int num = arr[x][y];
	int count = 0;
	while (!q.empty()) {
		curx = q.front().first;
		cury = q.front().second;
		
		count++;
		q.pop();

		for (int i = 0; i < 4; i++) {
			newx = curx + posx[i];
			newy = cury + posy[i];
			if (newx < 1 || newy < 1 || newx > n || newy > m || visit[newx][newy]) {
				continue;
			}
			if (arr[newx][newy] == num) {
				visit[newx][newy] = true;
				q.push(make_pair(newx, newy));
			}
		}
	}

	return count;
}
void move() {
	int newx, newy, temp;
	newx = dx + posx[d];
	newy = dy + posy[d];
	if (newx < 1 || newy < 1 || newx > n || newy > m) {
		d = (d + 2) % 4;
		newx = dx + posx[d];
		newy = dy + posy[d];
	}
	//주사위 변경
	if (d == 0) {
		//동
		temp = dice[1];
		dice[1] = dice[4];
		dice[4] = dice[3];
		dice[3] = dice[5];
		dice[5] = temp;
	 }
	else if (d == 2) {
		//서
		temp = dice[1];
		dice[1] = dice[5];
		dice[5] = dice[3];
		dice[3] = dice[4];
		dice[4] = temp;
	}
	else if (d == 1) {
		// 남
		temp = dice[1];
		dice[1] = dice[0];
		dice[0] = dice[3];
		dice[3] = dice[2];
		dice[2] = temp;
	}
	else {
		temp = dice[1];
		dice[1] = dice[2];
		dice[2] = dice[3];
		dice[3] = dice[0];
		dice[0] = temp;
	}
	dx = newx;
	dy = newy;
	bottom_num = dice[bottom];
	b_num = arr[dx][dy];
}

void cal_d() {
	if (bottom_num > b_num) {
		d = (d + 1) % 4;
	}
	else if (bottom_num < b_num) {
		d = d - 1;
		if (d < 0) {
			d += 4;
		}
	}
}
int main() {
	input();
	int res = 0;
	for (int i = 0; i < k; i++) {
		move();
		res += (arr[dx][dy] * bfs(dx, dy));
		cal_d();
	}
	cout << res;
	return 0;
}