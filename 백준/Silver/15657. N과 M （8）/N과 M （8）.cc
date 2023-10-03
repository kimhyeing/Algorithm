#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

int n,m;
vector<int>v;
vector<int>res;

void input() {
    cin>>n>>m;
    int a;
    for(int i=0;i<n;i++) {
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
}

void print() {
    for(int i=0;i<m;i++) {
        cout<<res[i]<<" ";
    }
    cout<<"\n";
}

void solve(int idx, int cnt) {
    if(cnt == m) {
        print();
        return;
    }

    for(int i=idx;i<n;i++) {
        res.push_back(v[i]);
        solve(i, cnt+1);
        res.pop_back();
    }
}

int main() {
    input();
    solve(0,0);
    return 0;
}