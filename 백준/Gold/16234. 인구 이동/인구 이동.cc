#include "iostream"
#include "vector"
#include "queue"
#include "cmath"

using namespace std;

int n,l,r;
int arr[50][50];
bool visited[51][51];
int dirx[4] = {0, -1, 0, 1};
int diry[4] = {1, 0, -1, 0};

void input() {
    cin>>n>>l>>r;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin>>arr[i][j];
        }
    }
}

void calculate(vector<pair<int, int> >& v, int v_sum) {
    int new_value = v_sum / (int)v.size();
    for(int i=0;i<v.size();i++) {
        arr[v[i].first][v[i].second] = new_value;
    }
}

bool move(int x, int y) {
    queue<pair<int,int> >q;
    q.push(make_pair(x,y));
    visited[x][y] = true;
    int newx, newy, diff;
    vector<pair<int, int> > v;
    v.push_back(make_pair(x,y));
    int v_sum = arr[x][y];
    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for(int i=0;i<4;i++) {
            newx = x+dirx[i];
            newy = y+diry[i];
            if(newx<0 || newy < 0 || newx >= n || newy >= n || visited[newx][newy]) continue;
            diff = abs(arr[x][y] - arr[newx][newy]);
            if(diff >= l && diff <= r) {
                visited[newx][newy] = true;
                q.push(make_pair(newx, newy));
                v.push_back(make_pair(newx, newy));
                v_sum += arr[newx][newy];
            }
        }
    }
    if(v.size() > 1) {
        calculate(v, v_sum);
        return true;
    }
    return false;
}

int solve() {
    int result = 0;
    bool isMove = true;
    while(isMove) {
        isMove = false;
        fill(&visited[0][0], &visited[n][n], false);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    if (move(i, j)) {
                        isMove = true;
                    }
                }
            }
        }
        if(isMove) result++;
    }
    return result;
}

int main() {
    input();
    cout<<solve();
    return 0;
}