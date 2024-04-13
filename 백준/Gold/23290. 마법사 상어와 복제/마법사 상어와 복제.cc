#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int m, s, sx, sy;
vector<int>arr[4][4];
vector<int>tempArr[4][4];
bool visited[4][4];
int smell[4][4];
int dirx[8] = { 0,-1,-1,-1,0,1,1,1 };
int diry[8] = { -1,-1,0,1,1,1,0,-1 };
int dirSx[4] = { -1,0,1,0 };
int dirSy[4] = { 0,-1,0,1 };

void input() {
	cin >> m >> s;
	int x, y, d;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> d;
		arr[x - 1][y - 1].push_back(d-1);
	}
	cin >> sx >> sy;
	sx--; sy--;
}

void moveFish() {
	bool isMove;
	int len,newx, newy, newd;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			len = arr[i][j].size();
			for (int t = 0; t < len; t++) {
				isMove = false;
				newd = arr[i][j][t];
				for (int d = 0; d < 8; d++) {
					if (d > 0) {
						newd -= 1;
						if (newd == -1) newd = 7;
					}
					newx = i + dirx[newd];
					newy = j + diry[newd];
					if (newx < 0 || newy < 0 || newx >= 4 || newy >= 4) continue;
					if (smell[newx][newy] > 0 || (newx == sx && newy == sy)) continue;
					isMove = true;
					break;
				}
				
				if (!isMove) {
					newx = i;
					newy = j;
					newd = arr[i][j][t];
				}
				tempArr[newx][newy].push_back(newd);
			}
		}
	}
}

int fishCnt, newx, newy;
vector<int>sharkDir;
void moveShark(int x, int y, vector<int>dlist, int cnt, bool vs[4][4]) {
	if (dlist.size() == 3) {
		if (fishCnt < cnt) {
			sharkDir = dlist;
			fishCnt = cnt;
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		newx = x + dirSx[i];
		newy = y + dirSy[i];
		if (newx < 0 || newy < 0 || newx >= 4 || newy >= 4) continue;
		bool tempVisited[4][4];
		copy(&vs[0][0], &vs[3][4], &tempVisited[0][0]);
		dlist.push_back(i);
		if (tempVisited[newx][newy]) {
			moveShark(newx, newy, dlist, cnt, tempVisited);
		}
		else {
			tempVisited[newx][newy] = true;
			moveShark(newx, newy, dlist, cnt + tempArr[newx][newy].size(), tempVisited);
		}
		dlist.pop_back();
	}
}

void makeSmell() {
	for (int i = 0; i < 3; i++) {
		sx += dirSx[sharkDir[i]];
		sy += dirSy[sharkDir[i]];
		if (tempArr[sx][sy].empty()) continue;
		tempArr[sx][sy].clear();
		smell[sx][sy] = 3;
	}
}

void decSmell() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (smell[i][j] == 0) continue;
			smell[i][j] -= 1;
		}
	}
}

void copyFish() {
	int len;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			len = tempArr[i][j].size();
			for (int t = 0; t < len; t++) {
				arr[i][j].push_back(tempArr[i][j][len - 1 - t]);
				tempArr[i][j].pop_back();
			}
		}
	}
}

int getResult() {
	int result = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			result += arr[i][j].size();
		}
	}
	return result;
}

void solve() {
	vector<int>templist;
	for (int i = 0; i < s; i++) {
		moveFish();

		fishCnt = -1;
		moveShark(sx, sy, templist, 0, visited);
		
		makeSmell();

		decSmell();

		copyFish();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	solve();
	cout << getResult();
	return 0;
}