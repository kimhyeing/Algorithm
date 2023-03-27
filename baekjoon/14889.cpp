#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

int n, s;
int arr[20][20];
int start, link, gap = INT32_MAX;
bool startTeam[20];

void calculate(bool team[20]) {
	int temp;
	start = link = 0;
	for (int i = 0; i < n; i++) {
		if (team[i]) {
			for (int j = 0; j < n; j++) {
				if (team[j]) {
					start += arr[i][j];
				}
			}
		}
		else {
			for (int j = 0; j < n; j++) {
				if (!team[j]) {
					link += arr[i][j];
				}
			}
		}
	}
	temp = abs(start - link);
	gap = min(gap, temp);
}

void dfs(int a, int count, bool team[20]) {
	if (count == n / 2) {
		calculate(team);
		return;
	}
	for (int i = a + 1; i < n; i++) {
		bool temp[20];
		copy(team, team + n, temp);
		temp[i] = true;
		dfs(i, count + 1, temp);
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	startTeam[0] = true;
	dfs(0, 1, startTeam);
	cout << gap;
	return 0;
}