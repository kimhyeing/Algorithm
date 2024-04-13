#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

struct machine {
	int x;
	int y;
	int d;
};
struct Wind {
	int x;
	int y;
	int value;
};

int dirx[4] = { 0,0,-1,1 };
int diry[4] = { 1,-1,0,0 };
int originTemp[20][20];
int incTemp[20][20];
int spreadTemp[20][20];
int AllSpreadTemp[20][20];
bool wall[4][20][20];
bool visited[20][20];
vector<machine>machineList;
vector<pair<int, int>>kList;
int R, C, K, choco;
const int RIGHT = 0, LEFT = 1, UP = 2, DOWN = 3;

void input() {
	cin >> R >> C >> K;
	int a;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> a;
			if (a == 0) continue;
			if (a == 5) {
				kList.push_back(make_pair(i, j));
			}
			else {
				machine mc = { i,j,a - 1 };
				machineList.push_back(mc);
			}
		}
	 }
	int w, t, x, y;
	cin >> w;
	for (int i = 0; i < w; i++) {
		cin >> x >> y >> t;
		x--; y--;
		if (t == 0) {
			if ((x - 1) >= 0) {
				wall[DOWN][x - 1][y] = true;
			}
			wall[UP][x][y] = true;
		}
		else {
			if ((y + 1) < C) {
				wall[LEFT][x][y + 1] = true;
			}
			wall[RIGHT][x][y] = true;
		}
	}
}

void spread(int x, int y, int d) {
	fill(&spreadTemp[0][0], &spreadTemp[R - 1][C], 0);
	int newx, newy, newd, nnewx, nnewy, curx, cury, curvalue, sdir,edir;
	queue<Wind>q;
	Wind wind = { x + dirx[d], y + diry[d], 5 };
	q.push(wind);
	spreadTemp[x + dirx[d]][y + diry[d]] = 5;
	while (!q.empty()) {
		curx = q.front().x;
		cury = q.front().y;
		curvalue = q.front().value;
		q.pop();

		if (curvalue == 1) continue;

		newx = curx + dirx[d];
		newy = cury + diry[d];
		if (newx < 0 || newy < 0 || newx >= R || newy >= C) continue;

		if (!wall[d][curx][cury]) { // no wall
			if (spreadTemp[newx][newy] == 0) {
				wind = { newx, newy, curvalue - 1 };
				q.push(wind);
				spreadTemp[newx][newy] = curvalue - 1;
			}
		}

		if (d == RIGHT || d == LEFT) {
			sdir = UP; edir = DOWN;
		}
		else {
			sdir = RIGHT; edir = LEFT;
		}

		for (int i = sdir; i <= edir; i++) {
			newx = curx + dirx[i];
			newy = cury + diry[i];
			if (newx < 0 || newy < 0 || newx >= R || newy >= C) continue;
			if (wall[i][curx][cury]) continue;

			nnewx = newx + dirx[d];
			nnewy = newy + diry[d];
			if (nnewx < 0 || nnewy < 0 || nnewx >= R || nnewy >= C) continue;
			if (wall[d][newx][newy]) continue;

			wind = { nnewx, nnewy, curvalue - 1 };
			q.push(wind);
			spreadTemp[nnewx][nnewy] = curvalue - 1;
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			AllSpreadTemp[i][j] += spreadTemp[i][j];
			if (AllSpreadTemp[i][j] < 0) {
				AllSpreadTemp[i][j] = 0;
			}
		}
	}
}

void spreadMerge() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			originTemp[i][j] += AllSpreadTemp[i][j];
			if (originTemp[i][j] < 0) {
				originTemp[i][j] = 0;
			}
		}
	}
}

void tempDivide() {
	fill(&incTemp[0][0], &incTemp[R - 1][C], 0);
	int dirarr[2] = { RIGHT, DOWN };
	int newx, newy, diff, d;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			for (int t = 0; t < 2; t++) {
				d = dirarr[t];
				newx = i + dirx[d];
				newy = j + diry[d];
				if (newx < 0 || newy < 0 || newx >= R || newy >= C) continue;
				if (wall[d][i][j]) continue;

				diff = (abs(originTemp[i][j] - originTemp[newx][newy]) / 4);
				if (diff == 0) continue;

				if (originTemp[i][j] > originTemp[newx][newy]) {
					incTemp[i][j] -= diff;
					incTemp[newx][newy] += diff;
				}
				else {
					incTemp[i][j] += diff;
					incTemp[newx][newy] -= diff;
				}
			}
		}
	}

	// merge
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			originTemp[i][j] += incTemp[i][j];
			if (originTemp[i][j] < 0) {
				originTemp[i][j] = 0;
			}
		}
	}
}

void edgeDesc() {
	int x, y;
	for (int i = 0; i < 2; i++) {
		if (i == 1) x = R - 1;
		else x = 0;

		for (int j = 0; j < C; j++) {
			if (originTemp[x][j] == 0) continue;
			originTemp[x][j]--;
		}
	}

	for (int j = 0; j < 2; j++) {
		if (j == 1) y = C - 1;
		else y = 0;

		for (int i = 1; i < R-1; i++) {
			if (originTemp[i][y] == 0) continue;
			originTemp[i][y]--;
		}
	}
}

bool isEnd() {
	int x, y;
	for (int i = 0; i < kList.size(); i++) {
		x = kList[i].first;
		y = kList[i].second;
		if (originTemp[x][y] < K) {
			return false;
		}
	}
	return true;
}

void solve() {
	for (int i = 0; i < machineList.size(); i++) {
		spread(machineList[i].x, machineList[i].y, machineList[i].d);
	}

	while (true) {
		spreadMerge();
		tempDivide();
		edgeDesc();
		choco++;
		if (isEnd()) break;
		if (choco > 100) break;
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	solve();
	cout << choco;
	return 0;
}