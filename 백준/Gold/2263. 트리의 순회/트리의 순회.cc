#include "iostream"

using namespace std;

const int MAX = 1e5+1;
int n;
int inOrder[MAX];
int postOrder[MAX];
int inOrderIdx[MAX];

void input() {
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>inOrder[i];
        inOrderIdx[inOrder[i]]=i;
    }
    for(int i=1;i<=n;i++) {
        cin>>postOrder[i];
    }
}

void solve(int ps, int pe, int is, int ie) {
    if(pe < ps || ie < is) return;
    cout<<postOrder[pe]<<" ";
    if(ps == pe) return;

    solve(ps, inOrderIdx[postOrder[pe]]-is+ps-1, is, inOrderIdx[postOrder[pe]]-1);
    solve(inOrderIdx[postOrder[pe]]-is+ps, pe-1, inOrderIdx[postOrder[pe]]+1, ie);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    input();
    solve(1, n, 1, n);
    return 0;
}