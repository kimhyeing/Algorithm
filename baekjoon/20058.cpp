#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

int n, q, width;
int arr[200][200];
vector<int>level_list;
int posx[4] = { 0, 1, 0, -1 };
int posy[4] = { 1,0,-1, 0 };
int temp_arr[200][200];
int visit[200][200];
int ice_sum, max_area, temp_area;

void input() {
	cin >> n >> q;
	width = (int)pow(2, n);
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < width; j++) {
			cin >> arr[i][j];
		}
	}

	int l;
	for (int i = 0; i < q; i++) {
		cin >> l;
		level_list.push_back(l);
	}
}

void move(int x, int y, int lv, int cur_width) {
	int last_x = x + cur_width - 1;
	int last_y = y + cur_width - 1;
	int dir = 0; // 오른쪽

	int temp = arr[x][y];
	
	int cur_x = x, cur_y = y, new_x, new_y, cur_d;
	int dec = 0, cur_len;
	for (int layer = cur_width / 2; layer > 0; layer--) {
		vector<pair<int, int>>v;
		if (layer == (cur_width / 2)) {
			dec = 0;
		}
		else {
			dec++;
		}
		cur_len = cur_width - 2 * dec;
		for (int d = 0; d < 5; d++) {
			if (d == 0) {
				cur_x = x + (cur_width / 2 - layer);//시작점
				cur_y = y + (cur_width / 2 - layer);
				cur_d = d;
			}
			else if (d >= 4)
				cur_d = 0;
			else
				cur_d = d;
			if (!v.empty()) {
				vector<pair<int, int>>temp;
				for (int i = 0; i < cur_len; i++) {
					new_x = cur_x + posx[cur_d] * i;
					new_y = cur_y + posy[cur_d] * i;
					temp.push_back(make_pair(new_x, new_y));
					if (i == (cur_len - 1)) {
						cur_x = new_x;
						cur_y = new_y;
					}
					temp_arr[new_x][new_y] = arr[v[i].first][v[i].second];
				}
				v = temp;
			}
			else {
				for (int i = 0; i < cur_len; i++) {
					new_x = cur_x + posx[cur_d] * i;
					new_y = cur_y + posy[cur_d] * i;
					v.push_back(make_pair(new_x, new_y));
					if (i == (cur_len - 1)) {
						cur_x = new_x;
						cur_y = new_y;
					}
				}
			}
		}
	}
}

void dfs(int x, int y) {
	visit[x][y] = true;
	if (arr[x][y] <= 0) {
		return;
	}
	int newx, newy;
	for (int i = 0; i < 4; i++) {
		newx = x + posx[i];
		newy = y + posy[i];
		if (newx < 0 || newy < 0 || newx >= width || newy >= width || visit[newx][newy] || arr[newx][newy] <= 0) {
			continue;
		}

		visit[newx][newy] = true;
		temp_area++;
		dfs(newx, newy);
	}
}

void solve() {
	int cur_width = 0;
	int ice_count = 0, newx, newy;
	copy(&arr[0][0], &arr[width][width], &temp_arr[0][0]);
	for (int i = 0; i < q; i++) {
		cur_width = pow(2, level_list[i]);

		for (int r = 0; r < width; r += cur_width) {
			for (int c = 0; c < width; c += cur_width) {
				move(r, c, level_list[i], cur_width);
			}
		}
		copy(&temp_arr[0][0], &temp_arr[width][width], &arr[0][0]);
		for (int r = 0; r < width; r++) {
			for (int c = 0; c < width; c++) {
				ice_count = 4;
				for (int d = 0; d < 4; d++) {
					newx = r + posx[d];
					newy = c + posy[d];
					if (newx < 0 || newy < 0 || newx >= width || newy >= width || arr[newx][newy] <= 0) {
						ice_count--;
					}
				}

				if (ice_count < 3 && arr[r][c] != 0) {
					temp_arr[r][c]--;
				}
			}
		}
		copy(&temp_arr[0][0], &temp_arr[width][width], &arr[0][0]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	input();
	solve();
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < width; j++) {
			if (arr[i][j] > 0 && !visit[i][j]) {
				dfs(i, j);
				max_area = max(max_area, temp_area + 1);
				temp_area = 0;
			}
			ice_sum += arr[i][j];
		}
	}

	cout << ice_sum << "\n" << max_area;
	return 0;
}