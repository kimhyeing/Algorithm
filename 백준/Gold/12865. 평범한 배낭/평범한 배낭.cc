#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

int n,k;
vector<pair<int,int> >obj;
const int MAX = 1e5+1;
int dp[101][MAX];

void input() {
    cin>>n>>k;
    int w,v;
    for(int i=0;i<n;i++) {
        cin>>w>>v;
        obj.push_back(make_pair(w,v));
    }
}

void solve() {
    for(int i=1;i<=n;i++) {
        int cur_w = obj[i-1].first;
        int cur_v = obj[i-1].second;
        for(int j=1;j<=k;j++) {
            if(cur_w <= j) {
                dp[i][j] = max(dp[i-1][j], cur_v + dp[i-1][j-cur_w]);
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
}

int main() {
    input();
    solve();
    cout<<dp[n][k];
}