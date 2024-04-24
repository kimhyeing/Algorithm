#include "iostream"

using namespace std;

int arr[1025][1025];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cin>>arr[i][j];
            arr[i][j] += (arr[i-1][j] + arr[i][j-1] -arr[i-1][j-1]);
        }
    }
    int x1,x2,y1,y2, res;
    for(int i=0;i<m;i++) {
        cin>>x1>>y1>>x2>>y2;
        res = arr[x2][y2] - arr[x2][y1-1] - arr[x1-1][y2] + arr[x1-1][y1-1];
        cout<<res<<"\n";
    }
    return 0;
}