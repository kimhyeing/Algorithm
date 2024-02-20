#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int arr[50][50];
bool visited[50][50];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int m, n, k;
        cin >> m >> n >> k;
        for (int j = 0; j < m; j++) {
            for (int z = 0; z < n; z++) {
                arr[j][z] = 0;
                visited[j][z] = false;
            }
        }
        for (int j = 0; j < k; j++) {
            int x, y;
            cin >> x >> y;
            arr[x][y] = 1;
        }
        int cnt = 0;
        queue <pair<int, int>> q;
        for (int j = 0; j < m; j++) {
            for (int z = 0; z < n; z++) {
                if (arr[j][z] == 1 && visited[j][z] == false) {
                    q.push(make_pair(j, z));
                    cnt++;
                }
                while (!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    if (arr[x][y] == 1 && visited[x][y] == false) {
                        for (int s = 0; s < 4; s++) {
                            int nx = x + dx[s];
                            int ny = y + dy[s];
                            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                            if (arr[nx][ny] == 1 && visited[nx][ny] == false) {
                                q.push(make_pair(nx, ny));
                            }
                        }
                        visited[x][y] = true;
                    }
                }
            }
        }
        cout << cnt << "\n";
    }

    return 0;
}