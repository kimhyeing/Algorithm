#include "iostream"

using namespace std;

const int MAX = 10001;
int dp[MAX];
int n;

int calculate(int a) {
    int i=0, temp = a, c=0;
    while(temp > 0) {
        temp = a;
        temp -= (2*i);
        if(temp%3 == 0) c++;
        i++;
    }
    return c;
}

int solve(int a) {
    if(dp[a]) return dp[a];
    return dp[a] = (solve(a-1) + calculate(a));
}

int main() {
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    int t;
    cin>>t;
    while(t--) {
        cin>>n;
        cout<<solve(n)<<"\n";
    }
    return 0;
}