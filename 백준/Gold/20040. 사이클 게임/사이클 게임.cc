#include "iostream"
#include "vector"

using namespace std;

const int MAX = 5*1e5;
int n,m;
int parent[MAX];
int children[MAX];
vector<pair<int,int> >v;

int Find(int x) {
    if(parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

bool Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    if(x!=y) {
        if(children[x] > children[y]) {
            parent[y] = x;
        }
        else {
            parent[x] = y;
        }
        return false;
    }
    return true;
}

void input() {
    cin>>n>>m;
    int a,b;
    for(int i=0;i<n;i++) {
        parent[i] = i;
        children[i] = 1;
    }

    for(int i=0;i<m;i++) {
        cin>>a>>b;
        if(Union(a,b)){
            cout<<i+1;
            return;
        }
    }
    cout<<0;
}

int main() {
    input();
    return 0;
}