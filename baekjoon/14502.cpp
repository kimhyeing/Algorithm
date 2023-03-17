#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int arr[9][9];
int posx[4] = { -1,0,1,0 };
int posy[4] = { 0,1,0,-1 };
int n, m, a, x, y, area, res;

void bfs(int a, int b, bool visit[9][9]) {
	queue<pair<int, int>>q;
	q.push(make_pair(a, b));
	int xx, yy;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			xx = x + posx[i];
			yy = y + posy[i];
			if (xx < 0 || yy < 0 || xx >= n || yy >= m)
				continue;
			if (arr[xx][yy] == 0 && visit[xx][yy] != true) {
				q.push(make_pair(xx, yy));
				visit[xx][yy] = true;
				area++;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<pair<int, int>>v;
	vector<pair<int, int>>avail;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a;
			arr[i][j] = a;
			if (a == 0) {
				avail.push_back(make_pair(i, j));
			}
			else if (a == 2) {
				v.push_back(make_pair(i, j));
			}
		}
	}

	int size = avail.size();
	int x1, y1, x2, y2, x3, y3;
	
	for (int i = 0; i < size; i++) {
		x1 = avail[i].first;
		y1 = avail[i].second;
		arr[x1][y1] = 1;
		for (int j = i + 1; j < size; j++) {
			x2 = avail[j].first;
			y2 = avail[j].second;
			arr[x2][y2] = 1;
			for (int k = j + 1; k < size; k++) {
				x3 = avail[k].first;
				y3 = avail[k].second;
				arr[x3][y3] = 1;

				bool visit[9][9] = { 0, };
				for (int t = 0; t < v.size(); t++) {
					x = v[t].first;
					y = v[t].second;
					bfs(x, y, visit);
				}
				area = avail.size() - area;
				res = max(res, area);
				arr[x3][y3] = 0;
				area = 0;
			}
			arr[x2][y2] = 0;
		}
		arr[x1][y1] = 0;
	}
	cout << res - 3;
	return 0;
}