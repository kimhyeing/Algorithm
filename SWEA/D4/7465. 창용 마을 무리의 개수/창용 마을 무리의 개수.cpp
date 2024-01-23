#include<iostream>
#include<unordered_set>

using namespace std;

int parent[101];
int level[101];
int n,m;

void init() {
    for(int i=1;i<=n;i++) {
        parent[i] = i;
    }
}

int Find(int x) {
    if(x == parent[x]) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    if(x!=y) {
        if(level[x] < level[y]) {
            parent[x] = y;
            level[y] += level[x];
        }
        else {
            parent[y] = x;
            level[x] += level[y];
        }
    }
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int a,b;
        cin>>n>>m;
        unordered_set<int>us;
        init();
        for(int i=0;i<m;i++) {
            cin>>a>>b;
            Union(a,b);
        }

        for(int i=1;i<=n;i++) {
            us.insert(Find(i));
        }
        cout<<"#"<<test_case<<" "<<us.size()<<"\n";
    }
    return 0;
}