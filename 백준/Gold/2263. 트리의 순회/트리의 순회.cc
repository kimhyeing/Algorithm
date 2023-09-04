#include "iostream"

using namespace std;

const int MAX = 1e5+1;
int n;
int inOrder[MAX];
int postOrder[MAX];

void input() {
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>inOrder[i];
    }
    for(int i=0;i<n;i++) {
        cin>>postOrder[i];
    }
}

int find(int is, int ie, int pr) {
    for(int i=is;i<=ie;i++) {
        if(inOrder[i] == postOrder[pr]) return i;
    }
}

int getRoot(int ps, int gap){
    return ps+gap;
}


void solve(int ps, int pe, int is, int ie) {
    int pr, ir;

    if(pe < ps || ie < is) return;
    cout<<postOrder[pe]<<" ";
    if(ps == pe) return;

    pr = pe;
    ir = find(is, ie, pr);
    pr = getRoot(ps, ir-is-1);
    solve(ps, pr, is, ir-1);
    solve(pr+1, pe-1, ir+1, ie);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    input();
   solve(0, n-1, 0, n-1);
    return 0;
}