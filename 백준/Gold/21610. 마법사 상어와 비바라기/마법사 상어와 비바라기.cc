#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

int n, m;
int arr[53][53];
bool pre_cloud[53][53];
vector<pair<int, int>>inst;
vector<pair<int, int>>cloud;

int posx[8] = { 0,-1,-1,-1,0,1,1,1 };
int posy[8] = { -1,-1,0,1,1,1,0,-1 };


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
		inst.push_back(make_pair(d - 1, s));
	}
	cloud.push_back(make_pair(n, 1));
	cloud.push_back(make_pair(n, 2));
	cloud.push_back(make_pair(n-1, 1));
	cloud.push_back(make_pair(n-1, 2));
}

int main() {
	input();
	int newx, newy, x, y, xdir, ydir;
	for (int idx = 0; idx < m; idx++) {
		vector<pair<int, int>>inc;
		//구름이동
		for (int i = 0; i < cloud.size(); i++) {
			x = cloud[i].first;
			y = cloud[i].second;
			xdir = posx[inst[idx].first];
			ydir = posy[inst[idx].first];
			newx = (x + xdir * inst[idx].second) % n;
			newy = (y + ydir * inst[idx].second) % n;
			if (newx <= 0)
				newx += n;
			if (newy <= 0)
				newy += n;
			// 물 양 증가
			arr[newx][newy]++;
			pre_cloud[newx][newy] = true;
			inc.push_back(make_pair(newx, newy));
		}
		//구름사라짐
		cloud.clear();

		//물복사버그
		for (int i = 0; i < inc.size(); i++) {
			x = inc[i].first;
			y = inc[i].second;
			int inc_count = 0;
			for (int j = 1; j <= 7; j+=2) {
				newx = x + posx[j];
				newy = y + posy[j];
				if (newx < 1 || newy < 1 || newx > n || newy > n || arr[newx][newy] <= 0)
					continue;
				inc_count++;
			}
			arr[x][y] += inc_count;
		}
		//구름생성
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (arr[i][j] >= 2 && !pre_cloud[i][j]) {
					arr[i][j] -= 2;
					cloud.push_back(make_pair(i, j));
				}
			}
		}
		memset(pre_cloud, false, sizeof(pre_cloud));
	}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			res += arr[i][j];
		}
	}
	cout << res;
	return 0;
}