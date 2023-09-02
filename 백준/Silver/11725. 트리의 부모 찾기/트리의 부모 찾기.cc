#include "iostream"
#include "vector"

using namespace std;

const int MAX = 100001;
vector<int>tree[MAX];
int parent[MAX];
int visit[MAX];
int n;

void solve(int a) {
    for(int i=0;i<tree[a].size();i++) {
        if(!visit[tree[a][i]]) {
            visit[tree[a][i]] = true;
            parent[tree[a][i]] = a;
            solve(tree[a][i]);
        }
    }
}

int main() {
    cin>>n;

    int a,b;
    for(int i=0;i<n-1;i++) {
        cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    solve(1);
    for(int i=2;i<=n;i++) {
        cout<<parent[i]<<"\n";
    }
    return 0;
}