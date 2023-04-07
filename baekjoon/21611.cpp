#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

int n, m, sx, sy;
int arr[52][52];
int posx[4] = { 0,1,0,-1 };
int posy[4] = { -1,0,1,0 };
int res[4];
bool boombable;
vector<pair<int, int>>inst;

void input() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	int d, s;
	for (int i = 0; i < m; i++) {
		cin >> d >> s;
		if (d == 1) d = 3;
		else if (d == 2) d = 1;
		else if (d == 3) d = 0;
		else d = 2;
		inst.push_back(make_pair(d, s));
	}
	sx = sy = (n + 1) / 2;
}

void move() {
	int curx = sx + posx[0];
	int cury = sy + posy[0];
	int curd = 0;
	int count = 1;
	int dis = 1;
	int newx, newy, newd, new_count, new_dis;
	bool init = false;

	while (true) {
		while (arr[curx][cury] != 0) {
			if (curx == 1 && cury == 1) {
				return;
			}
			if (count == dis) {
				if (curd == 1 || curd == 3)
					dis++;
				count = 0;
				curd = (curd + 1) % 4;
			}
			curx = curx + posx[curd];
			cury = cury + posy[curd];
			count++;
		}

		if (!init) {
			newx = curx;
			newy = cury;
			new_count = count;
			new_dis = dis;
			newd = curd;
			init = true;
		}
		while (arr[newx][newy] == 0) {
			if (newx == 1 && newy == 1) {
				return;
			}
			if (new_count == new_dis) {
				if (newd == 1 || newd == 3)
					new_dis++;
				new_count = 0;
				newd = (newd + 1) % 4;
			}
			newx = newx + posx[newd];
			newy = newy + posy[newd];
			new_count++;
		}

		swap(arr[curx][cury], arr[newx][newy]);
	}
}

void bomb() {
	int curx = sx + posx[0];
	int cury = sy + posy[0];
	int curd = 0;
	int count = 1;
	int dis = 1;
	int newx, newy, newd, new_count, new_dis;
	bool init = false;
	int boom = 0, ball_num;

	newx = curx;
	newy = cury;
	new_count = count;
	new_dis = dis;
	newd = curd;
	while (true) {
		boom = 0;
		if (curx == 1 && cury == 1) {
			return;
		}
		if (curx < 1 || cury < 1) {
			return;
		}

		ball_num = arr[curx][cury];
		while (arr[newx][newy] == ball_num) {
			if (newx < 1 || newy < 1) {
				return;
			}
			boom++;

			if (new_count == new_dis) {
				if (newd == 1 || newd == 3)
					new_dis++;
				new_count = 0;
				newd = (newd + 1) % 4;
			}
			newx = newx + posx[newd];
			newy = newy + posy[newd];
			new_count++;
		}

		if (boom >= 4) {
			boombable = true;
			while (curx != newx || cury != newy) {
				arr[curx][cury] = 0;
				if (curx == 1 && cury == 1) {
					return;
				}
				if (count == dis) {
					if (curd == 1 || curd == 3)
						dis++;
					count = 0;
					curd = (curd + 1) % 4;
				}
				curx = curx + posx[curd];
				cury = cury + posy[curd];
				count++;
				res[ball_num]++;
			}
		}
		else {
			curx = newx;
			cury = newy;
			count = new_count;
			dis = new_dis;
			curd = newd;
		}
	}
}

void change() {
	int curx = sx + posx[0];
	int cury = sy + posy[0];
	int curd = 0;
	int count = 1;
	int dis = 1;
	int ball_count = 0, ball_num;

	vector<int>new_arr;
	while (true) {
		ball_count = 0;
		if (curx == 1 && cury == 1) {
			break;
		}
		if (arr[curx][cury] == 0)
			break;

		ball_num = arr[curx][cury];
		while (arr[curx][cury] == ball_num) {
			ball_count++;
			if (curx == 1 && cury == 1) {
				break;
			}
			if (count == dis) {
				if (curd == 1 || curd == 3)
					dis++;
				count = 0;
				curd = (curd + 1) % 4;
			}
			curx = curx + posx[curd];
			cury = cury + posy[curd];
			count++;
		}
		if (new_arr.size() >= (n * n - 1))
			break;
		new_arr.push_back(ball_count);
		if (new_arr.size() >= (n * n - 1))
			break;
		new_arr.push_back(ball_num);
		if (new_arr.size() >= (n * n - 1))
			break;
	}

	curx = sx + posx[0];
	cury = sy + posy[0];
	curd = 0;
	count = 1;
	dis = 1;
	memset(arr, 0, sizeof(arr));
	for (int i = 0; i < new_arr.size(); i++) {
		arr[curx][cury] = new_arr[i];
		if (curx == 1 && cury == 1) {
			return;
		}
		if (count == dis) {
			if (curd == 1 || curd == 3)
				dis++;
			count = 0;
			curd = (curd + 1) % 4;
		}
		curx = curx + posx[curd];
		cury = cury + posy[curd];
		count++;
	}
}
int main() {
	input();
	int d, s, newx, newy;

	for (int i = 0; i < m; i++) {
		d = inst[i].first;
		s = inst[i].second;
		for (int j = 1; j <= s; j++) {
			newx = sx + j * posx[d];
			newy = sy + j * posy[d];
			arr[newx][newy] = 0;
		}
		
		move();
		boombable = true;
		while (boombable) {
			boombable = false;
			bomb();
			move();
		}
		change();
	}
	int boom_sum = 0;
	for (int i = 1; i <= 3; i++) {
		boom_sum += (i * res[i]);
	}
	cout << boom_sum;

	return 0;
}