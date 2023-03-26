#include<iostream>

using namespace std;

int room[51][51];
int posx[4] = { -1,0,1,0 };
int posy[4] = { 0,1,0,-1 };

int main() {
	int n, m, r, c, d, newx, newy, newdir;
	cin >> n >> m;
	cin >> r >> c >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> room[i][j];
		}
	}
	int x = r, y = c, dir = d, res = 0;
	bool success;
	while (true) {
		if (room[x][y] == 0) {
			room[x][y] = 2;
			res++;
		}

		success = false;
		newdir = dir;
		for (int i = 0; i < 4; i++) {
			newdir = (newdir + 3) % 4;
			newx = x + posx[newdir];
			newy = y + posy[newdir];
			if (newx < 0 || newy < 0 || newx >= n || newy >= m)
				continue;
			if (room[newx][newy] == 0) {
				success = true;
				break;
			}
		}

		if (success) {
			dir = newdir;
		}
		else {
			newx = x + posx[(dir + 2) % 4];
			newy = y + posy[(dir + 2) % 4];
			if (newx < 0 || newy < 0 || newx >= n || newy >= m || room[newx][newy] == 1) {
				break;
			}
		}
		x = newx;
		y = newy;
	}
	cout << res;
	return 0;
}