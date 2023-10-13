#include<iostream>
#include<algorithm>

using namespace std;

int n, l;
int arr[100][100];
int road = 0, j, i, temp;
bool success = true;

void rowSolve() {
	for (int i = 0; i < n; i++) {
		j = 0;
		bool g[100] = { false, };
		while (true) {
			if (j >= n - 1) {
				//cout << i << "번째 행\n";
				road++;
				break;
			}

			if (arr[i][j] - arr[i][j + 1] == 1 && !g[j + 1]) {
				if (j + l <= n - 1 && arr[i][j + l] == arr[i][j + 1]) {
					temp = j + 1;
					success = true;
					while (temp != j + l) {
						if (arr[i][temp] != arr[i][temp + 1] || g[temp + 1]) {
							success = false;
							break;
						}
						temp++;
					}

					if (success) {
						g[temp] = true;
						j = temp;
					}
					else break;
				}
				else break;
			}
			else if (arr[i][j] - arr[i][j + 1] == -1) {
				if (j + 1 - l >= 0 && arr[i][j + 1 - l] == arr[i][j] && !g[j + 1 - l]) {
					temp = j;
					success = true;
					while (temp != j + 1 - l) {
						if (g[temp] || arr[i][temp] != arr[i][temp - 1]) {
							success = false;
							break;
						}
						temp--;
					}

					if (success) {
						g[temp] = true;
						j++;
					}
					else break;
				}
				else break;
			}
			else if (arr[i][j] == arr[i][j + 1]) {
				j++;
			}
			else break;
		}
	}
}

void columnSolve() {
	for (int j = 0; j < n; j++) {
		i = 0;
		bool g[100] = { false, };
		while (true) {
			if (i >= n - 1) {
				//cout << j << "번째 열\n";
				road++;
				break;
			}

			if (arr[i][j] - arr[i + 1][j] == 1 && !g[i + 1]) {
				if (i + l <= n - 1 && arr[i + l][j] == arr[i + 1][j]) {
					temp = i + 1;
					success = true;
					while (temp != i + l) {
						if (arr[temp][j] != arr[temp + 1][j] || g[temp + 1]) {
							success = false;
							break;
						}
						temp++;
					}

					if (success) {
						g[temp] = true;
						i = temp;
					}
					else break;
				}
				else break;
			}
			else if (arr[i][j] - arr[i + 1][j] == -1) {
				if (i + 1 - l >= 0 && arr[i + 1 - l][j] == arr[i][j] && !g[i + 1 - l]) {
					temp = i;
					success = true;
					while (temp != i + 1 - l) {
						if (g[temp] || arr[temp][j] != arr[temp - 1][j]) {
							success = false;
							break;
						}
						temp--;
					}

					if (success) {
						g[temp] = true;
						i++;
					}
					else break;
				}
				else break;
			}
			else if (arr[i][j] == arr[i + 1][j]) {
				i++;
			}
			else break;
		}
	}
}
int main() {
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	
	rowSolve();
	columnSolve();
	cout << road;
	return 0;
}