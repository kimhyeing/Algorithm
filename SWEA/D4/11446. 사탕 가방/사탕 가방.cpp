#include <iostream>
#include <algorithm>

using namespace std;

long long arr[101];

int main() {
    long long t, n, m, left, right, mid, temp, res;
    cin>>t;
    for(int i=0;i<t;i++) {
        cin>>n>>m;
        left = 1;
        right = 0;
        for(int j=0;j<n;j++) {
            cin>>arr[j];
            right = max(right, arr[j]);
        }

        left = 1;

        res = 0;
        while(left<=right) {
            mid = (left+right)/2;
            temp = 0;
            for(int k=0;k<n;k++) {
                temp += arr[k]/mid;
            }
            if(temp >= m) {
                left = mid+1;
                res = mid;
            }
            else {
                right = mid-1;
            }
        }
        cout<<"#"<<i+1<<" "<<res<<"\n";
    }


    return 0;
}