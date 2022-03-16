#include<iostream>
#include<queue>

using namespace std;

struct tomato {
	int x;
	int y;
	int z;
	int level;
};

int m, n, h, x, y, z;
int matrix[100][100][100];
vector<tomato>v;

int posx[4] = { -1,0,1,0 };
int posy[4] = { 0,1,0,-1 };
int posz[2] = { -1, 1 };

int bfs() {
	queue<tomato>q;
	int day = 0;
	for (int i = 0; i < v.size(); i++) {
		tomato t = { v[i].x, v[i].y, v[i].z, v[i].level };
		q.push(t);
	}

	while (!q.empty()) {
		tomato T = q.front();
		x = T.x;
		y = T.y;
		z = T.z;
		q.pop();

		int a, b, c;
		for (int i = 0; i < 6; i++) {
			if (i < 4) {
				a = x + posx[i];
				b = y + posy[i];
				c = z;
			}
			else {
				a = x; b = y;
				c = z + posz[i - 4];
			}

			if (a < 0 || b < 0 || c < 0 || a >= n || b >= m || c >= h)
				continue;

			if (matrix[a][b][c] == 0) {
				matrix[a][b][c] = T.level + 1;
				tomato t = { a,b,c,T.level + 1 };
				q.push(t);
				day = t.level;
			}
		}
	}

	bool full = true;
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (matrix[i][j][k] == 0) {
					full = false;
					break;
				}
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
	cin >> m >> n >> h;
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> value;
				matrix[i][j][k] = value;
				if (value == 1) {
					tomato t = { i,j,k,0 };
					v.push_back(t);
				}
				else { preComplete = false; }
			}
		}
	}

	if (preComplete)
		cout << 0;
	else {
		cout << bfs();
	}
	return 0;
}