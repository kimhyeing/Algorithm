#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, sx, sy;
int dirx[4] = { -1,1,0,0 };
int diry[4] = { 0,0,-1,1 };
const int UP = 0, DOWN = 1, LEFT = 2, RIGHT = 3;
int arr[50][50];
pair<int, int>mlist[100];
int score[3];
vector<pair<int, int>>root;

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	int d, s;
	for (int i = 0; i < m; i++) {
		cin >> d >> s;
		mlist[i] = make_pair(d-1, s);
	}
	sx = sy = n / 2;
}

int nextDir(int d) {
	if (d == LEFT) return DOWN;
	else if (d == DOWN) return RIGHT;
	else if (d == RIGHT) return UP;
	else return LEFT;
}

void setRoot() {
	int x = sx, y = sy, cur_dist = 0, dist = 1, dir = LEFT, cnt = 0;
	bool isIce = false;
	while (x != 0 || y != 0) {
		x += dirx[dir];
		y += diry[dir];
		root.push_back(make_pair(x, y));
		cur_dist++;
		if (cur_dist == dist) {
			cur_dist = 0;
			cnt++;
			dir = nextDir(dir);
		}
		if (cnt == 2) {
			cnt = 0;
			dist++;
		}
	}
}

void bombItem(int x, int y) {
	score[arr[x][y] - 1]++;
	arr[x][y] = 0;
}

int getResult() {
	int result = 0;
	for (int i = 1; i <= 3; i++) {
		result += (i * score[i - 1]);
	}
	return result;
}

void ice(int d, int s) {
	int x = sx, y = sy;
	for (int i = 0; i < s; i++) {
		x += dirx[d];
		y += diry[d];
		if (x < 0 || y < 0 || x >= n || y >= n || !arr[x][y]) break;
		arr[x][y] = 0;
	}
}

void move() {
	int iceIdx = -1, x, y, iceCount = 0, preX, preY;
	for (int i = 0; i < root.size(); i++) {
		x = root[i].first;
		y = root[i].second;
		if (arr[x][y] == 0) {
			iceCount++;
		}
		else if ((i - iceCount) >= 0){
			preX = root[i - iceCount].first;
			preY = root[i - iceCount].second;
			swap(arr[preX][preY], arr[x][y]);
		}
	}
}

int bomb() {
	int bombCount = 0;
	int num = -1, cnt = 0, x, y, tempx, tempy;
	for (int i = 0; i < root.size(); i++) {
		x = root[i].first;
		y = root[i].second;
		if (arr[x][y] != num && cnt < 4) {
			num = arr[x][y];
			cnt = 1;
		}
		else if (arr[x][y] != num && cnt >= 4) {
			bombCount++;
			for (int j = (i - 1); j > (i - 1 - cnt); j--) {
				tempx = root[j].first;
				tempy = root[j].second;

				bombItem(tempx, tempy);
			}
			num = arr[x][y];
			cnt = 1;
		}
		else {
			cnt++;
		}
	}
	return bombCount;
}

void change() {
	vector<int>newItem;
	int num, cnt = 0, x, y;
	for (int i = 0; i < root.size(); i++) {
		x = root[i].first;
		y = root[i].second;
		if (i == 0) {
			num = arr[x][y];
		}
		if (arr[x][y] != num) {
			newItem.push_back(cnt);
			newItem.push_back(num);
			num = arr[x][y];
			cnt = 1;
			if (arr[x][y] == 0) break;
		}
		else {
			cnt++;
		}
	}
	
	for (int i = 0; i < root.size(); i++) {
		x = root[i].first;
		y = root[i].second;
		if (i >= (newItem.size())) {
			arr[x][y] = 0;
		}
		else {
			arr[x][y] = newItem[i];
		}
	}
	
}
void solve() {
	int d, s;
	for (int i = 0; i < m; i++) {
		d = mlist[i].first;
		s = mlist[i].second;
		ice(d, s);
		move();
		while (bomb()) {
			move();
		}
		change();
	}
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	setRoot();
	solve();
	cout << getResult();
	return 0;
}