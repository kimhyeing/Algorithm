#include "iostream"
#include "vector"
#include "queue"
#include "algorithm"

using namespace std;

const int MAX = 1e4 + 1;
vector<pair<int,int> > graph[MAX];
int visit[MAX];
int n,m;
int start, dest;

int bfs() {
    queue<pair<int,int> >q;
    q.push(make_pair(start, 1e9+1));
    int cur, w, child, child_w, res=0, min_w;
    while(!q.empty()) {
        cur = q.front().first;
        w = q.front().second;
        q.pop();

        if(cur == dest) {
            res = max(res, w);
        }
        else {
            if(visit[cur] > w) continue;
            for (int i=0;i<graph[cur].size();i++) {
                child = graph[cur][i].first;
                child_w = graph[cur][i].second;
                min_w = min(w, child_w);
                if(child != cur && visit[child] < min_w) {
                    visit[child] = min_w;
                    q.push(make_pair(child, min_w));
                }
            }
        }
    }
    return res;
}

void input() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>>n>>m;
    int a,b,c;
    for(int i=0;i<m;i++) {
        cin>>a>>b>>c;
        graph[a].push_back(make_pair(b,c));
        graph[b].push_back(make_pair(a,c));
    }
    cin>>start>>dest;
}
int main() {
    input();
    cout<<bfs();
    return 0;
}