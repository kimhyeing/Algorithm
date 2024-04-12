#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
#include<cmath>
using namespace std;

int n, k, result;
vector<deque<int>>v;
int dirx[2] = { 0,1 };
int diry[2] = { 1,0 };
const int LEFT = 0;
const int DOWN = 1;

void input() {
	cin >> n >> k;
	v.resize(n);
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v[i].push_back(a);
	}
}

void minFishIncrease() {
	int minFish = INT32_MAX;
	for (int i = 0; i < n; i++) {
		minFish = min(minFish, v[i].front());
	}

	int temp;
	for (int i = 0; i < n; i++) {
		if (v[i].front() == minFish) {
			temp = v[i].front() + 1;
			v[i].pop_front();
			v[i].push_front(temp);
		}
	}
}

int firstLotation() {
	int cnt = 1;
	int same = 0, des, start, next, height=0;
	int i = 0;
	while(true){
		des = i + cnt;
		start = des - 1;
		if ((des + height) > n) {
			return i;
		}
		
		for (int j = 0; j < cnt; j++) {
			next = 0;
			start = des - 1 - j;
			while (!v[start].empty()) {
				v[des + next].push_back(v[start].front());
				v[start].pop_front();
				next++;
			}
			height = v[des].size();
		}
		i += cnt;
		
		same++;
		if (same == 2) {
			same = 0;
			cnt++;
		}
	}
}

void divideFish(int si) {
	int len = n - si;
	vector<deque<int>>temp = v;
	vector<vector<int>>temp_arr(len);
	int height = temp[si].size();
	for (int i = si; i < n; i++) {
		for (int j = 0; j < height; j++) {
			if (!temp[i].empty()) {
				temp_arr[i - si].push_back(temp[i].front());
				temp[i].pop_front();
			}
		}
	}

	vector<vector<int>>IncAmount = temp_arr;

	int newx, newy, next_height;
	for (int i = 0; i < temp_arr.size(); i++) {
		height = temp_arr[i].size();
		// down
		if (i < (temp_arr.size() - 1)) {
			next_height = temp_arr[i + 1].size();
			
			for (int j = 0; j < next_height; j++) {
				newx = i + dirx[DOWN];
				newy = j + diry[DOWN];
				int diff = abs(temp_arr[i][j] - temp_arr[newx][newy])/5;
				if (diff > 0) {
					if (temp_arr[i][j] > temp_arr[newx][newy]) {
						IncAmount[i][j] -= diff;
						IncAmount[newx][newy] += diff;
					}
					else {
						IncAmount[i][j] += diff;
						IncAmount[newx][newy] -= diff;
					}
				}
			}
		}

		for (int j = 0; j < height-1; j++) {
			newx = i + dirx[LEFT];
			newy = j + diry[LEFT];
			int diff = abs(temp_arr[i][j] - temp_arr[newx][newy])/5;
			if (diff > 0) {
				if (temp_arr[i][j] > temp_arr[newx][newy]) {
					IncAmount[i][j] -= diff;
					IncAmount[newx][newy] += diff;
				}
				else {
					IncAmount[i][j] += diff;
					IncAmount[newx][newy] -= diff;
				}
			}
		}
	}

	temp.resize(n);
	int dqIdx = si;
	for (int i = 0; i < len; i++) {
		height = IncAmount[i].size();
		for (int j = 0; j < height; j++) {
			temp[dqIdx].push_back(IncAmount[i][j]);
		}
		dqIdx++;
	}
	v = temp;
}

void makeOneLine(int si) {
	vector<deque<int>>temp(n);
	int i = 0;
	for (int idx = si; idx < n; idx++) {
		while (!v[idx].empty()) {
			temp[i].push_back(v[idx].front());
			v[idx].pop_front();
			i++;
		}
	}
	v = temp;
}

int secondLotation() {
	int start = 0, end = n;
	int mid = (start + end) / 2;
	for (int i = 0; i < mid; i++) {
		v[n - 1 - i].push_back(v[i].front());
		v[i].pop_front();
	}
	start = mid;
	mid = (start + end) / 2;
	int cnt = 1;
	for (int i = (mid-1); i >= start; i--) {
		while (!v[i].empty()) {
			v[i + cnt].push_back(v[i].back());
			v[i].pop_back();
		}
		cnt += 2;
	}
	return mid;
}

int getDiff() {
	int max_fish = 0, min_fish = 10001;
	for (int i = 0; i < n; i++) {
		max_fish = max(max_fish, v[i].front());
		min_fish = min(min_fish, v[i].front());
	}
	return (max_fish - min_fish);
}

void solve() {
	int idx, dff;
	while (true) {
		result++;
		minFishIncrease();

		idx = firstLotation();

		divideFish(idx);

		makeOneLine(idx);

		idx = secondLotation();

		divideFish(idx);

		makeOneLine(idx);
		
		dff = getDiff();
		if (dff <= k) break;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	solve();
	cout << result;
	return 0;
}