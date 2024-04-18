#include "iostream"
#include "algorithm"

using namespace std;

const int MAX = 100000;
int dp[2][MAX];
int arr[2][MAX];

int main() {
    int t, n, result;
    
    cin>>t;
    while(t--) {
        cin>>n;
        for (int j=0;j<2;j++) {
            for (int i = 0; i < n; i++) {
                cin>>arr[j][i];
            }
        }

        dp[0][0] = arr[0][0];
        dp[1][0] = arr[1][0];
        if(n>1) {
            dp[0][1] = arr[0][1] + dp[1][0];
            dp[1][1] = arr[1][1] + dp[0][0];
        }
        for (int i = 2; i < n; i++) {
            dp[0][i] = arr[0][i] + max(dp[1][i-1], dp[1][i-2]);
            dp[1][i] = arr[1][i] + max(dp[0][i-1], dp[0][i-2]);
        }
        result = max(dp[0][n-1], dp[1][n-1]);
        cout<<result<<"\n";
    }

    return 0;
}