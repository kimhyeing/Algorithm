#include <iostream>
#include <algorithm>
using namespace std;

const int SIZE = 500;
pair<int, int> matrix[SIZE];
int dp[500][500];

int solve(int start, int end) {
    if(dp[start][end] || start == end) return dp[start][end];
    for(int i=start+1;i<=end;i++) {
        int x = solve(start, i-1);
        int y = solve(i,end);
        int r = matrix[start].first; int m = matrix[i].first; int c = matrix[end].second;
        int cur =  r * m * c;
        if(i == start+1) dp[start][end] = x+y+cur;
        else dp[start][end] = min(dp[start][end], x+y+cur);
    }
    return dp[start][end];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n,r,c;
    cin>>n>>r>>c;
    matrix[0] = make_pair(r,c);
    for(int i=1;i<n;i++) {
        cin>>r>>c;
        matrix[i] = make_pair(r,c);
        dp[i-1][i] = matrix[i-1].first * matrix[i-1].second * matrix[i].second;
    }
    cout<<solve(0,n-1);

    return 0;
}
