#include "iostream"

using namespace std;

const int DIV_NUM = 1e9;
int dp[101][10];
int n;

int solve(int level, int num) {
    if(dp[level][num]) return dp[level][num];
    if(level==1) return dp[level][num] = 1;

    if(num == 9) {
        return dp[level][num] = solve(level-1, num-1);
    }
    else if(num == 0) {
        return dp[level][num] = solve(level-1, num+1);
    }
    return dp[level][num] = (solve(level-1, num-1)+solve(level-1, num+1))%DIV_NUM;
}

int main() {
    cin>>n;
    int res = 0;
    for(int i=1;i<=9;i++){
        res = (res+solve(n,i))%DIV_NUM;
    }
    cout<<res;
    return 0;
}