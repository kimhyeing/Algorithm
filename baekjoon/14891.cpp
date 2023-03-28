#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;

int arr[4][8];

int main() {
	int k, a, pos;
	int top[4] = { 0, };
	pair<int, int> lr[4] = {
		make_pair(6, 2),
		make_pair(6, 2),
		make_pair(6, 2),
		make_pair(6, 2),
	};
	string s;
	for (int i = 0; i < 4; i++) {
		cin >> s;
		for (int j = 0; j < 8; j++) {
			arr[i][j] = s[j] - '0';
		}
	}
	cin >> k;
	int move[4] = { 0, };
	int temp;
	for (int i = 0; i < k; i++) {
		cin >> a >> pos;
		a--;
		move[a] = pos;
		temp = a;
		while (temp < 3) {
			if (arr[temp][lr[temp].second] != arr[temp + 1][lr[temp + 1].first]) {
				move[temp + 1] = -1 * move[temp];
				temp++;
			}
			else break;
		}
		temp = a;
		while (temp > 0) {
			if (arr[temp][lr[temp].first] != arr[temp - 1][lr[temp - 1].second]) {
				move[temp - 1] = -1 * move[temp];
				temp--;
			}
			else break;
		}
		
		for (int j = 0; j < 4; j++) {
			if (move[j] == 1) {
				top[j] = (top[j] + 7) % 8;
				lr[j] = make_pair((lr[j].first + 7) % 8, (lr[j].second + 7) % 8);
			}
			else if (move[j] == -1) {
				top[j] = (top[j] + 1) % 8;
				lr[j] = make_pair((lr[j].first + 1) % 8, (lr[j].second + 1) % 8);
			}
		}

		memset(move, 0, sizeof(int)*4);
	}
	double res = 0;
	for (int i = 0; i < 4; i++) {
		res += arr[i][top[i]] * pow(2, i);
	}
	cout << res;
	return 0;
}