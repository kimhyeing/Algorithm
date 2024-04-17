#include "iostream"

using namespace std;

long long arr[16];

int main() {
    int t,n,m;
    long long result;
    arr[0] = arr[1] = 1;
    for(int i=2;i<=15;i++) {
        arr[i] = i*arr[i-1];
    }
    cin>>t;
    long long temp;
    while(t--) {
        cin>>n>>m;
        result = 1;
        if((m-n) < n) {
            n = (m-n);
        }
        temp = arr[n];

        for(int i=n;i>0;i--) {
            if(temp > m && (temp%m) == 0){
                temp /= m;
            }
            else {
                result *= m;
            }
            m--;
        }
        result /= temp;
        cout << result<<"\n";
    }
    return 0;
}