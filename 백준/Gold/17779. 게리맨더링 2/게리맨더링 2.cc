#include "iostream"

using namespace std;

int n;
int arr[21][21];

void input() {
    cin>>n;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cin>>arr[i][j];
        }
    }
}

int sum[6];
int diff_min = INT32_MAX;
void getNum(int x, int y, int d1, int d2) {
    fill_n(sum, 6,0);
    int maxn = 0, minn = INT32_MAX;
    for(int r=1;r<=n;r++) {
        for(int c=1;c<=n;c++) {
            if(r<(x+d1) && c <= y) {
                if((r+c) >= (x+y)) {
                    sum[5]+=arr[r][c];
                } else {
                    sum[1]+=arr[r][c];
                }
            }
            else if(r<=(x+d2) && c > y && c<=n) {
                if(r>=x && c <= (y+d2) && (r-x) >= (c-y)) {
                    sum[5]+=arr[r][c];
                } else {
                    sum[2]+=arr[r][c];
                }
            }
            else if((x+d1)<=r && c < (y-d1+d2)) {
                if (r <= (x + d1 + d2) && c >= (y - d1) && (r - (x + d1) <= c - (y - d1))) {
                    sum[5]+=arr[r][c];
                } else {
                    sum[3]+=arr[r][c];
                }
            }
            else if((x+d2) < r && (y-d1+d2) <= c) {
                if(r<=(x+d1+d2) && c <= (y+d2) && (r-(x+d2)) <= -(c-(y+d2))) {
                    sum[5]+=arr[r][c];
                } else {
                    sum[4]+=arr[r][c];
                }
            }
            else {
                sum[5]+=arr[r][c];
            }
        }
    }
    for(int i=1;i<=5;i++) {
        maxn = max(maxn, sum[i]);
        minn = min(minn, sum[i]);
    }

    diff_min = min(diff_min, (maxn-minn));
}

void solve() {
    for(int x=1;x<=n-2;x++) {
        for(int y=2;y<=n-1;y++) {
            for(int d1=1;(x+d1+1)<=n;d1++) {
                if((y-d1)<1) break;
                for(int d2=1;(x+d1+d2)<=n;d2++){
                    if((y+d2)>n) break;
                    getNum(x,y,d1,d2);
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    solve();
    cout<<diff_min;
    return 0;
}