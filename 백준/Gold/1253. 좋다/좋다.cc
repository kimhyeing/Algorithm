#include "iostream"
#include "algorithm"
#include "set"
#include "map"

using namespace std;

int arr[2000];

int main() {
    int n;
    cin>>n;
    map<int,int>ma;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
        auto temp = ma.find(arr[i]);
        if(temp != ma.end()) {
            temp->second += 1;
        }
        else {
            ma.insert(make_pair(arr[i], 1));
        }
    }
    sort(arr, arr+n);
    int cur, a1, a2, diff, cnt = 0;
    for(int i=0;i<n;i++) {
        cur = arr[i];
        if(cur == 0 && ma.find(cur)->second >= 3) {
            cnt++;
            continue;
        }
        for(int j=0;j<n;j++) {
            if(i==j) continue;
            a1 = arr[j];
            diff = cur-a1;
            if(a1 == diff) {
                if(a1 == cur) {
                    if(ma.find(a1)->second >= 3) {
                        cnt++;
                        break;
                    }
                    continue;
                }
                else if(ma.find(a1)->second >= 2) {
                    cnt++;
                    break;
                }
                continue;

            }
            auto temp = ma.find(diff);
            if(temp != ma.end()) {
                if(diff == cur && (temp->second < 2)) continue;
                cnt++; break;
            }
        }
    }
    cout<<cnt;
    return 0;
}