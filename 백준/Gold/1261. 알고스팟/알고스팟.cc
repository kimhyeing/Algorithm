#include "iostream"
#include "queue"
#include "algorithm"

using namespace std;

int n,m;
int map[101][101];
int visit[101][101];
int dirx[4] = {-1,0,1,0};
int diry[4] = {0,1,0,-1};

struct miro{
    int x;
    int y;
    int value;
};

struct cmp{
    bool operator()(miro& a, miro& b) {
        if(a.value == b.value) {
            if(a.x == b.x)
                return a.y < b.y;
            return a.x < b.x;
        }
        return a.value > b.value;
    }
};

void input() {
    cin>>m>>n;
    char c;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++){
            cin>>c;
            map[i][j] = c-'0';
        }
    }
}

void solve() {
    priority_queue<miro, vector<miro>, cmp>pq;
    fill(&visit[0][0], &visit[n][m], -1);
    miro d = {0,0,0};
    pq.push(d);
    int res = 1e4+1;
    visit[0][0] = 0;
    while(!pq.empty()) {
        int x = pq.top().x;
        int y = pq.top().y;
        int cur_dist = pq.top().value;
        pq.pop();

        if(x==(n-1) && y == (m-1)) {
            res = min(res, cur_dist);
            continue;
        }

        for(int i=0;i<4;i++) {
            int newx = x + dirx[i];
            int newy = y + diry[i];
            if(newx < 0 || newy < 0 || newx >= n || newy >= m)
                continue;

            miro new_data = {newx, newy, cur_dist};
            if(map[newx][newy] == 1)
                new_data.value += 1;
            if(visit[newx][newy] < 0 || visit[newx][newy] > new_data.value) {
                visit[newx][newy] = new_data.value;
                pq.push(new_data);
            }
        }
    }
    cout<<res;
}

int main() {
    input();
    solve();
    return 0;
}