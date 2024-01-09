#include "iostream"
#include "deque"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,l, a;
    deque<pair<int,int> >dq;
    cin>>n>>l;
    for(int i=1;i<=n;i++) {
        cin>>a;
        while (!dq.empty() && dq.back().first >= a) {
            dq.pop_back();
        }
        dq.push_back(make_pair(a,i));
        while (dq.front().second < (i-l+1)) {
            dq.pop_front();
        }
        cout<<dq.front().first<<" ";
    }
    return 0;
}