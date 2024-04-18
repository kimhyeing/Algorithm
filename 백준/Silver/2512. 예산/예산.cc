#include "iostream"
#include "algorithm"

using namespace std;

int arr[10000];
int n, m, sum, max_n;
void setSum(int upNum){
    sum = 0;
    for(int i=0;i<n;i++) {
        if(upNum < arr[i]) {
            sum += (upNum*(n-i));
            break;
        }
        else {
            sum += arr[i];
        }
    }
}

int main() {
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
        sum += arr[i];
    }
    sort(arr, arr+n);
    cin>>m;
    max_n = arr[n-1];
    if(m >= sum) {
        cout<<max_n;
    }
    else {
        int start = 1;
        int end = max_n;
        int mid;
        int max_up = 0;
        while(start<=end) {
            mid = (start+end)/2;
            setSum(mid);
            if(sum <= m) {

                max_up = max(mid, max_up);
                start = mid+1;
            }
            else {
                end = mid-1;
            }
        }
        cout<<max_up<<"\n";
    }
}