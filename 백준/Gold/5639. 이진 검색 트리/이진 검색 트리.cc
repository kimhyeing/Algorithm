#include "iostream"

using namespace std;

const int MAX = 1e4;
int tree[MAX];

void postOrder(int start, int end) {
    if(start > end) return;
    if(start == end) {
        cout<<tree[start]<<"\n";
        return;
    }
    int idx = start+1;
    while(tree[start] > tree[idx]) {
        idx++;
        if(idx > end) break;
    }
    postOrder(start+1, idx-1);
    postOrder(idx, end);
    cout<<tree[start]<<"\n";
}

int main() {
    int n, idx = 0;
    while(cin>>n) {
        tree[idx++] = n;
    }
    postOrder(0, idx-1);
    return 0;
}