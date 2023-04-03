#include<iostream>
#include<vector>
#include<set>

using namespace std;

struct ball {
	int x;
	int y;
	int m;
	int s;
	int d;
};

int N, M, K, r, c, m, s, d, res;
int posx[8] = { -1, -1,0,1,1,1,0,-1s };
int posy[8] = { 0,1,1,1,0,-1,-1,-1 };
vector<ball> arr[51][51];
vector<ball>v;

void input() {
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		cin >> r >> c >> m >> s >> d;
		v.push_back(ball{ r,c,m,s,d });
	}
}

int main() {
	input();
	int newx, newy, newm, news, msum, ssum, first_d;
	int dis_x, dis_y;
	bool same;
	ball b;

	for (int i = 0; i < K; i++) {
		set<pair<int, int>>bs;
		set<pair<int, int>>b_one;
		for (int j = 0; j < v.size(); j++) {
			b = v[j];
			
			r = b.x;
			c = b.y;
			dis_x = posx[b.d] * b.s;
			dis_y = posy[b.d] * b.s;
			newx = (r + dis_x) % N;
			newy = (c + dis_y) % N;
			if (newx < 1) {
				newx += N;
			}
			if (newy < 1) {
				newy += N;
			}

			v[j] = ball{ newx, newy, b.m, b.s, b.d };
			arr[newx][newy].push_back(ball{ newx, newy, b.m, b.s, b.d });
			if (arr[newx][newy].size() > 1)
				bs.insert(make_pair(newx, newy));
		}
		for (int j = 0; j < v.size(); j++) {
			b = v[j];
			r = b.x;
			c = b.y;


			if (arr[r][c].size() != 1)
				continue;

			b_one.insert(make_pair(r, c));
		}

		vector<ball>newv;

		for (auto a : b_one) {
			r = a.first;
			c = a.second;

			newv.push_back(arr[r][c][0]);
			arr[r][c].clear();
		}

		for (auto a : bs) {
			r = a.first;
			c = a.second;
			if (arr[r][c].size() < 2)
				continue;

			msum = ssum = 0;
			same = true;
			for (int j = 0; j < arr[r][c].size(); j++) {
				b = arr[r][c][j];
				if (j == 0)
					first_d = b.d;
				else {
					if (first_d % 2 != b.d % 2)
						same = false;
				}
				msum += b.m;
				ssum += b.s;
			}

			newm = msum / 5;
			news = ssum / arr[r][c].size();
			if (newm > 0) {
				for (int j = 0; j < 4; j++) {
					if (same) {
						b = ball{ r,c,newm, news, j * 2 };
					}
					else {
						b = ball{ r,c,newm, news, (j + 1) * 2 - 1 };
					}
					newv.push_back(b);
				}
			}
			arr[r][c].clear();
		}
		v.clear();
		v = newv;
	}

	for (ball _b : v) {
		res += _b.m;
	}
	cout << res;
	return 0;
}