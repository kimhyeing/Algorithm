#include "iostream"

using namespace std;

int n,m;

void print(int* a, int count) {
    for(int i=0;i<=count;i++) {
        cout<<a[i]<<" ";
    }
}

void solve(int* a, int count) {
    if(count == m-1) {
        print(a, count);
        cout<<"\n";
        return;
    }
    for(int i=a[count];i<=n;i++) {
        a[count+1] = i;
        solve(a, count+1);
    }
}

int main() {
    cin>>n>>m;
    int* arr = new int[8];
    for(int i=1;i<=n;i++) {
        arr[0] = i;
        solve(arr, 0);
    }
    return 0;
}