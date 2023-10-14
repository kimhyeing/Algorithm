#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<string>

using namespace std;

struct fish {
	int x;
	int y;
	int d;
};

int m, s, sx, sy;
int posx[8] = { 0,-1,-1, -1,0,1,1,1 };
int posy[8] = { -1,-1,0,1,1,1,0,-1 };
vector<fish> arr[6][6];
vector<fish> temp_arr[6][6];
vector<fish> default_arr[6][6];
bool visit[6][6];
int real_move[3];
int smell_list[6][6];
vector<pair<int, int>>sv;

void input() {
	cin >> m >> s;
	int x, y, d;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> d;
		arr[x][y].push_back({ x,y, d - 1});
	}
	cin >> sx >> sy;
}

void move() {
	int x, y, newx, newy, newd;
	fish f;
	bool success;
	int rc = 0;
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			for (int k = 0; k < arr[i][j].size(); k++) {
				
				f = arr[i][j][k];
				x = f.x;
				y = f.y;
				newd = f.d;
				success = true;
				rc = 0;
				while (true) {
					if (rc > 7) {
						success = false;
						newd = f.d;
						break;
					}
					newx = x + posx[newd];
					newy = y + posy[newd];
					rc++;

					if (newx < 1 || newy < 1 || newx > 4 || newy > 4 || (newx == sx && newy == sy) || smell_list[newx][newy] > 0) {
						newd = newd - 1;
						if (newd < 0) newd += 8;
						continue;
					}
					break;
				}
				if (success) {
					x = newx;
					y = newy;
				}
				temp_arr[x][y].push_back({ x,y,newd });
			}
		}
	}
}

bool avail(int x, int y) {
	if (x < 1 || y < 1 || x > 4 || y > 4)
		return false;
	return true;
}
void move_shark() {
	int p[4] = { 2,0,6,4 };
	int d;
	int newx, newy;
	int one_sx, one_sy, two_sx, two_sy, three_sx, three_sy;
	int sum, real_sum = -1;

	for (int i = 0; i < 4; i++) {
		d = p[i];
		sum = 0;
		one_sx = sx;
		one_sy = sy;
		newx = one_sx + posx[d];
		newy = one_sy + posy[d];
		if (!avail(newx, newy))
			continue;

		sum += temp_arr[newx][newy].size();
		two_sx = newx;
		two_sy = newy;
		for (int j = 0; j < 4; j++) {
			d = p[j];
			newx = two_sx + posx[d];
			newy = two_sy + posy[d];
			if (!avail(newx, newy))
				continue;
			sum += temp_arr[newx][newy].size();
			three_sx = newx;
			three_sy = newy;
			for (int k = 0; k < 4; k++) {
				d = p[k];
				newx = three_sx + posx[d];
				newy = three_sy + posy[d];
				if (!avail(newx, newy))
					continue;
				if (newx != two_sx || newy != two_sy) {
					sum += temp_arr[newx][newy].size();
					if (sum > real_sum) {
						real_sum = sum;
						real_move[0] = p[i];
						real_move[1] = p[j];
						real_move[2] = p[k];
					}
					sum -= temp_arr[newx][newy].size();
				}
				else {
					if (sum > real_sum) {
						real_sum = sum;
						real_move[0] = p[i];
						real_move[1] = p[j];
						real_move[2] = p[k];
					}
				}
			}
			sum -= temp_arr[three_sx][three_sy].size();

		}
	}
}

void reduce_smell() {
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			if (smell_list[i][j] > 0)
				smell_list[i][j]--;
		}
	}
}

void copy_fish() {
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			for (int k = 0; k < temp_arr[i][j].size(); k++) {
				arr[i][j].push_back(temp_arr[i][j][k]);
			}
		}
	}
	copy(&default_arr[0][0], &default_arr[5][5], &temp_arr[0][0]);
}

long long int cal() {
	long long int res = 0;
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			res += arr[i][j].size();
		}
	}
	return res;
}
int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	input();
	
	int newx, newy,temp_sx, temp_sy;
	for (int i = 0; i < s; i++) {
		move();
		move_shark();
		
		temp_sx = sx;
		temp_sy = sy;
		reduce_smell();
		for (int j = 0; j < 3; j++) {
			newx = temp_sx + posx[real_move[j]];
			newy = temp_sy + posy[real_move[j]];

			if (temp_arr[newx][newy].size() > 0) {
				smell_list[newx][newy] = 2;
			}
			temp_arr[newx][newy].clear();
			temp_sx = newx;
			temp_sy = newy;
		}
		
		sx = temp_sx;
		sy = temp_sy;

		copy_fish();
	}
	cout << cal();
	
	return 0;
}