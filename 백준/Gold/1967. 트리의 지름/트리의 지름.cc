#include "iostream"
#include "vector"
#include "cstring"

using namespace std;

const int MAX = 1e5+1;
vector<pair<int, int> > tree[MAX];
int visit[MAX];
int n, res, last;

void input() {
    cin>>n;
    int a,b,w;
    for(int i=0;i<n-1;i++) {
        cin>>a>>b>>w;
        tree[a].push_back(make_pair(b,w));
        tree[b].push_back(make_pair(a,w));
    }
}

void dfs(int cur, int sum) {
    visit[cur] = 1;
    for (int i=0;i<tree[cur].size();i++) {
        int child = tree[cur][i].first;
        if(!visit[child]) {
            dfs(child, sum + tree[cur][i].second);
        }
    }
    if(res < sum) {
        last = cur;
        res = sum;
    }
}

void solve() {
    dfs(1, 0);
    memset(visit, 0, sizeof(visit));
    dfs(last, 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    input();
    solve();
    cout<<res;
    return 0;
}