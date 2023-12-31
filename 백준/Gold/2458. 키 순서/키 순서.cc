#include "iostream"
#include "queue"
#include "vector"
#include "cstring"

using namespace std;

const int MAX = 500;
vector<int>graph[MAX+1];
vector<int>graph_inv[MAX+1];
bool visit[MAX+1];
int n,m;

void input() {
    cin>>n>>m;
    int a, b;
    for(int i=0;i<m;i++) {
        cin>>a>>b;
        graph[a].push_back(b);
        graph_inv[b].push_back(a);
    }
}

int bfs(int a) {
    memset(visit, false, n+1);
    queue<int>q;
    q.push(a);
    visit[a] = true;
    int res = 0;
    while(!q.empty()) {
        res++;
        int cur = q.front();
        q.pop();
        for(int next : graph[cur]) {
            if(!visit[next]) {
                visit[next] = true;
                q.push(next);
            }
        }
    }
    return res;
}

int bfs_inv(int a) {
    memset(visit, false, n+1);
    queue<int>q;
    q.push(a);
    visit[a] = true;
    int res = 0;
    while(!q.empty()) {
        res++;
        int cur = q.front();
        q.pop();
        for(int next : graph_inv[cur]) {
            if(!visit[next]) {
                visit[next] = true;
                q.push(next);
            }
        }
    }
    return res-1;
}

int solve() {
    int res = 0;
    for(int i=1;i<=n;i++) {
        if((bfs(i)+bfs_inv(i)) == n) {
            res++;
        }
    }
    return res;
}

int main() {
    input();
    cout<<solve();
    return 0;
}