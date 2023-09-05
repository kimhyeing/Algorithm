#include "iostream"
#include "algorithm"

using namespace std;

vector<int>list;
vector<int>list_sub;

int n, c;
void input() {
    cin>>n>>c;
    int a;
    for(int i=0;i<n;i++) {
        cin>>a;
        list.push_back(a);
    }
    sort(list.begin(), list.end());
    for(int i=1;i<n;i++) {
        list_sub.push_back(list[i]-list[i-1]);
    }
}

int calculate(int gap) {
    int temp=0, res=1;
    for(int i=0;i<n-1;i++) {
       temp+=list_sub[i];
        if(temp >= gap) {
            temp = 0;
            res++;
        }
    }
    return res;
}

int solve() {
    int min_dis = 0;
    int max_dis = list[n-1]-list[0];
    int mid, temp;
    int res = 0;
    while(min_dis<=max_dis) {
        mid = (max_dis + min_dis)/2;
        temp = calculate(mid);
        if(temp < c) {
            max_dis = mid-1;
        }
        else {
            min_dis = mid+1;
            res = max(res, mid);
        }
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    input();
    cout<<solve();
    return 0;
}