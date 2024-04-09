#include "iostream"
#include "queue"
#include "algorithm"
#include "vector"

using namespace std;

int n,m, vl, empty_cnt;
vector<pair<int, int> > virus_list;
int arr[50][50];
int root[50][50];
int dirx[4] = {-1, 0, 1, 0};
int diry[4] = {0, 1,0, -1};

void print() {
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cout<<root[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

void input() {
    cin>>n>>m;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin>>arr[i][j];
            if(arr[i][j] == 2) {
                virus_list.push_back(make_pair(i,j));
            }
            else if(arr[i][j] == 0) empty_cnt++;
        }
    }
    vl = virus_list.size();
}

vector<int>idx_list;
int res = INT32_MAX;

int bfs() {
    queue<pair<int, int> >q;
    fill(&root[0][0], &root[n-1][n], 0);
    for(int il:idx_list) {
        q.push(virus_list[il]);
        root[virus_list[il].first][virus_list[il].second] = 1;
    }
    int x, y, newx, newy, max_time = 0, cnt=0;
    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        if(arr[x][y] == 0) {
            max_time = max(max_time, root[x][y] - 1);
            if(max_time > res) return res;
        }

        for(int i=0;i<4;i++) {
            newx = x+dirx[i];
            newy = y+diry[i];
            if(newx< 0 || newy < 0 || newx >= n || newy >= n) continue;
            if(arr[newx][newy] == 1 || root[newx][newy] != 0) continue;
            if(arr[newx][newy] == 0) {
                cnt++;
            }
            root[newx][newy] = root[x][y] + 1;
            q.push(make_pair(newx, newy));
        }
    }
    if(cnt == empty_cnt) return max_time;
    return res;
}

void combination(int cur, int cnt) {
    if(cnt == m) {
        res = min(res, bfs());
        return;
    }
    for(int i=cur;i<vl;i++) {
        idx_list.push_back(i);
        combination(i+1, cnt+1);
        idx_list.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    if(empty_cnt == 0) cout<<0;
    else {
        combination(0, 0);
        if (res == INT32_MAX) cout << -1;
        else cout << res;
    }
    return 0;
}