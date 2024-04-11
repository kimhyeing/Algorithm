#include<iostream>

using namespace std;

struct shark {
	int num;
	int dir;
	int cursec;
};

int n, m, k, sec;
shark arr[20][20];
int d[401][4][4];
int posx[4] = { -1, 1, 0, 0 };
int posy[4] = { 0, 0, -1 ,1 };
pair<int, int> s[401];
bool died[401];
int newdir_list[401];

void move() {
	int x, y, newx, newy, curdir, newdir, live = m;

	while (true) {
		if (sec > 1000 || live == 1) return;

		sec++;
		for (int i = 1; i <= m; i++) {
			if (died[i]) continue;

			x = s[i].first;
			y = s[i].second;
			curdir = arr[x][y].dir;
			bool moved = false;
			shark cur_shark = arr[x][y];

			for (int j = 0; j < 4; j++) {
				newdir = d[i][curdir][j];
 				newx = x + posx[newdir];
				newy = y + posy[newdir];
				if (newx < 0 || newy < 0 || newx >= n || newy >= n)
					continue;

				
				shark s1 = arr[newx][newy];
				if (arr[newx][newy].num != 0 && (s1.cursec + k) >= sec)
					continue;
				
				moved = true;
				newdir_list[i] = newdir;
				s[i] = make_pair(newx, newy);
				break;
			}

			if (!moved && !died[i]) {
				for (int j = 0; j < 4; j++) {
					newdir = d[i][curdir][j];
					newx = x + posx[newdir];
					newy = y + posy[newdir];
					if (newx < 0 || newy < 0 || newx >= n || newy >= n || arr[newx][newy].num != i)
						continue;

					moved = true;
					newdir_list[i] = newdir;
					s[i] = make_pair(newx, newy);
					break;
				}
			}
		}

		for (int sh = 1; sh <= m; sh++) {
			if (died[sh]) continue;
			x = s[sh].first;
			y = s[sh].second;
			newdir = newdir_list[sh];
			for (int com = sh + 1; com <= m; com++) {
				newx = s[com].first;
				newy = s[com].second;
				if (x == newx && y == newy && !died[com]) {
					died[com] = true;
					live--;
				}
			}
			arr[x][y] = shark{ sh,  newdir, sec };
		}
	}
}

void input() {
	int a;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a;
			arr[i][j] = shark{ a, 0, 0 };
			if (a > 0) {
				s[a] = make_pair(i, j);
			}
		}
	}
	int x, y;
	for (int i = 1; i <= m; i++) {
		cin >> a;
		x = s[i].first;
		y = s[i].second;
		arr[x][y] = shark{
			arr[x][y].num,
			a - 1,
			arr[x][y].cursec
		};
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < 4; j++) {
			for (int t = 0; t < 4; t++) {
				cin >> a;
				d[i][j][t] = a - 1;
			}
		}
	}
}

int main() {
	input();
	move();
	if (sec > 1000)
		sec = -1;
	cout << sec;
	return 0;
}