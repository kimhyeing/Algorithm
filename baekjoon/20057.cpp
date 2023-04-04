#include<iostream>
#include<vector>

using namespace std;

int n, x, y, newx, newy, res;
int arr[500][500];
int posx[4] = { 0, 1, 0, -1 };
int posy[4] = { -1,0,1,0 };
int a = 0, s5 = 1, l1 = 2, r1 = 3, l7 = 4, r7 = 5, l2 = 6, r2 = 7, l10 = 8, r10 = 9;

bool outOfRange(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= n)
		return true;
	else
		return false;
}

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
}

int main() {
	input();
	x = y = n / 2;
	int dir = 0, count = 0, s = 1;
	int cx, cy, ax, ay;
	int amount;
	
	while (true) {
		vector<pair<int, int>>v(10);
		vector<int>mv(10);
		if (x == 0 && y == 0)
			break;
		
		// 1. 좌표 계산
		newx = x + posx[dir];
		newy = y + posy[dir];
		
		ax = newx + posx[dir];
		ay = newy + posy[dir];
		v[a] = make_pair(ax, ay);
		v[s5] = make_pair(ax + posx[dir], ay + posy[dir]);

		// 2. 모래계산
		amount = arr[newx][newy];
		mv[l1] = mv[r1] = (int)(amount * 0.01);
		mv[l2] = mv[r2] = (int)(amount * 0.02);
		mv[s5] = (int)(amount * 0.05);
		mv[l7] = mv[r7] = (int)(amount * 0.07);
		mv[l10] = mv[r10] = (int)(amount * 0.1);
		mv[a] = amount - (mv[l1]*2 + mv[l2]*2 + mv[s5] + mv[l7]*2 + mv[l10]*2);
		
		// 3. 좌표 추가 계산
		if (dir == 0 || dir == 2) {
			v[l1] = make_pair(x - 1, y);
			v[r1] = make_pair(x + 1, y);
			v[l7] = make_pair(newx - 1, newy);
			v[r7] = make_pair(newx + 1, newy);
			v[l2] = make_pair(newx -2, newy);
			v[r2] = make_pair(newx + 2, newy);
			v[l10] = make_pair(ax - 1, ay); 
			v[r10] = make_pair(ax + 1, ay);
		}
		else {
			v[l1] = make_pair(x, y - 1);
			v[r1] = make_pair(x, y + 1);
			v[l7] = make_pair(newx, newy - 1);
			v[r7] = make_pair(newx, newy + 1);
			v[l2] = make_pair(newx, newy - 2);
			v[r2] = make_pair(newx, newy + 2);
			v[l10] = make_pair(ax, ay - 1);
			v[r10] = make_pair(ax, ay + 1);
		}

		// 4. 모래 분배
		for (int i = 0; i < v.size(); i++) {
			cx = v[i].first;
			cy = v[i].second;
			if (outOfRange(cx, cy)) {
				res += mv[i];
			}
			else {
				arr[cx][cy] += mv[i];
			}
		}

		// 5. 다음 방향 및 이동해야할 거리 계산
		count++;
		if (count == s) {
			count = 0;
			// s 증가시기
			if (dir == 1 || dir == 3) {
				s++;
			}
			dir = (dir + 1) % 4;
		}
		arr[newx][newy] = 0;
		x = newx;
		y = newy;
	}
	cout << res;

	return 0;
}