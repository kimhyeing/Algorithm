#include "iostream"
#include "vector"
using namespace std;

const int MAX = 13;
int k;
vector<int>v;
int number[MAX];
int selected[MAX];

void print() {
    for(auto num: v) {
        cout<<num<<" ";
    }
    cout<<"\n";
}

void solve(int idx, int cnt) {
    if(cnt == 6) {
        print();
        return;
    }

    for(int i=idx;i<k;i++) {
        if(selected[i]) continue;
        selected[i] = true;
        v.push_back(number[i]);
        solve(i, cnt+1);
        selected[i] = false;
        v.pop_back();
    }
}

void input() {
    while(cin>>k) {
        if(k == 0) break;
        for(int i=0;i<k;i++) {
            cin>>number[i];
        }
        solve(0,0);
        cout<<"\n";
    }
}

int main() {
    input();
    return 0;
}