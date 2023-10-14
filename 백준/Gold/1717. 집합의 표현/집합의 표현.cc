#include "iostream"

using namespace std;

const int MAX = 1e6+1;
int n,m;
int parent[MAX];

int Find(int x) {
    if(parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    if(x!=y) {
        parent[y] = x;
    }
}

bool isUnion(int x, int y) {
    x = Find(x);
    y = Find(y);
    if(x!=y) {
        return false;
    }
    return true;
}


void input() {
    cin>>n>>m;
    int a, b, c;
    for(int i=1;i<=n;i++) {
        parent[i] = i;
    }
    for(int i=0;i<m;i++) {
        cin>>a>>b>>c;
        if(a == 0){
            Union(b,c);
        }
        else {
            if(isUnion(b,c)){
                cout<<"yes\n";
            }
            else cout<<"no\n";
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    input();
    return 0;
}