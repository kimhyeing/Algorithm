#include<iostream>
#include<queue>

using namespace std;

struct tomato {
	int x;
	int y;
	int level;
};

int m, n, x, y;
int matrix[1000][1000];
vector<tomato>v;

int posx[4] = { -1,0,1,0 };
int posy[4] = { 0,1,0,-1 };

int bfs() {
	queue<tomato>q;
	int day = 0;
	for (int i = 0; i < v.size(); i++) {
		tomato t = { v[i].x, v[i].y, v[i].level };
		q.push(t);
	}

	while (!q.empty()) {
		bool tomatoEx = false;
		tomato T = q.front();
		x = T.x;
		y = T.y;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int a = x + posx[i];
			int b = y + posy[i];
			if (a < 0 || b < 0 || a >= n || b >= m)
				continue;

			if (matrix[a][b] == 0) {
				matrix[a][b] = T.level + 1;
				tomato t = { a,b,T.level + 1 };
				q.push(t);
				day = t.level;
			}
		}
	}

	bool full = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (matrix[i][j] == 0) {
				full = false;
				break;
			}
		}
	}

	if (full)
		return day;
	return -1;
}

int main() {
	int value;
	bool preComplete = true;
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> value;
			matrix[i][j] = value;
			if (value == 1) {
				tomato t = { i,j,0 };
				v.push_back(t);
			}
			else { preComplete = false; }
		}
	}

	if (preComplete)
		cout << 0;
	else {
		cout << bfs();
	}
	return 0;
}