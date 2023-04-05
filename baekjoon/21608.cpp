#include<iostream>
#include<set>
#include<vector>

using namespace std;

int n, std_num;
struct seat {
	int like_num;
	int empty_num;
	int r;
	int c;
};

int arr[21][21];
set<int>like[401];
vector<int>v;
int posx[4] = { -1,0,1,0 };
int posy[4] = { 0,1,0,-1 };

struct comp {
	bool operator() (const seat& s1, const seat& s2) const {
		if (s1.like_num == s2.like_num) {
			if (s1.empty_num == s2.empty_num) {
				if (s1.r == s2.r) {
					return s1.c < s2.c;
				}
				return s1.r < s2.r;
			}
			return s1.empty_num > s2.empty_num;
		}
		return s1.like_num > s2.like_num;
	}
};

void input() {
	cin >> n;
	std_num = n * n;
	int me, s;
	for (int i = 1; i <= std_num; i++) {
		cin >> me;
		v.push_back(me);
		for (int j = 0; j < 4; j++) {
			cin >> s;
			like[me].insert(s);
		}
	}
}

int main() {
	input();
	int newx, newy, ls, es, me;
	int x, y;
	for (int idx = 0; idx < std_num; idx++) {
		me = v[idx];
		set<seat, comp>seat_set;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (arr[i][j] == 0) {
					ls = es = 0;

					for (int d = 0; d < 4; d++) {
						newx = i + posx[d];
						newy = j + posy[d];
						if (newx < 1 || newy < 1 || newx > n || newy > n)
							continue;

						if (arr[newx][newy] == 0) {
							es++;
						}
						else if (like[me].find(arr[newx][newy]) != like[me].end()) {
							ls++;
						}
					}
					seat_set.insert(seat{ ls,es,i,j });
				}
			}
		}
		
		x = seat_set.begin()->r;
		y = seat_set.begin()->c;
		arr[x][y] = me;
	}

	int res = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			me = arr[i][j];
			ls = 0;

			for (int d = 0; d < 4; d++) {
				newx = i + posx[d];
				newy = j + posy[d];
				if (newx < 1 || newy < 1 || newx > n || newy > n)
					continue;

				if (like[me].find(arr[newx][newy]) != like[me].end()) {
					ls++;
				}
			}

			if (ls == 0)
				res += 0;
			else if (ls == 1)
				res += 1;
			else if (ls == 2)
				res += 10;
			else if (ls == 3)
				res += 100;
			else if (ls == 4)
				res += 1000;
		}
	}
	cout << res;
	return 0;
}