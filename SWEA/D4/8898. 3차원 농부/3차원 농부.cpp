#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX = 500000;
int cow[MAX+1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t,n,m,c1,c2,z, idx, res, temp, cnt;
    bool isDouble;
    cin>>t;
    for(int k=1;k<=t;k++) {
        res = INT32_MAX;
        cnt = 0;
        cin>>n>>m;
        cin>>c1>>c2;
        for(int i=0;i<n;i++) {
            cin>>cow[i];
        }
        sort(cow, cow+n);
        for(int i=0;i<m;i++) {
            isDouble = false;
            cin>>z;
            idx = lower_bound(cow, cow+n, z) - cow;
            if(idx > 0 && idx < n) {
                temp = min(abs(cow[idx]-z), abs(cow[idx-1]-z));
                if(abs(cow[idx]-z) == abs(cow[idx-1]-z)) {
                    isDouble = true;
                }
            }
            else if (idx==0) temp = abs(cow[idx]-z);
            else temp = abs(cow[n-1]-z);

            if(res >= temp) {
                if (res > temp) {
                    res = temp;
                    cnt = 1;
                }
                else if (res == temp) {
                    cnt++;
                }

                if (isDouble) cnt++;
            }
        }
        res+=abs(c1-c2);
        cout<<"#"<<k<<" "<<res<<" "<<cnt<<"\n";
    }

    return 0;
}