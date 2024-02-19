#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

int n, a, x;
vector<int>v;

void input() {
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>a;
        v.push_back(a);
    }
    cin>>x;
    sort(v.begin(), v.end());
}

int solve() {
    int left, right, mid, temp, cnt = 0;
    for(int i=0;i<n-1;i++) {
        a = v[i]; temp = x-a;
        left = i+1; right = n-1;
        while(left<=right) {
            mid=(left+right)/2;
            if(v[mid] == temp) {
                cnt++;
                break;
            }
            else if(v[mid] < temp) left = mid+1;
            else right = mid-1;
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    cout<<solve();
    
    return 0;
}