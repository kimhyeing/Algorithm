#include "iostream"
#include "cmath"

using namespace std;

const int MAX = 1e6+1;
int n, m, k, unit;
long long tree[MAX*4];

void setUnit() {
    int h = (int)ceil(log2(n));
    unit = 1<<h;
}

int getTreeIndex(int index) {
    return unit+index-1;
}

void input() {
    cin>>n>>m>>k;
    setUnit();
    for(int i=unit; i<(unit+n); i++) {
        cin>>tree[i];
    }
}

void build(){
    for(int i=unit-1;i>0;i--) {
        tree[i] = tree[i*2]+tree[i*2+1];
    }
}

void update(int index, long long value) {
    index = getTreeIndex(index);
    long long gap = value - tree[index];
    while(index) {
        tree[index] += gap;
        index /= 2;
    }
}

long long query(int start, int end) {
    start = getTreeIndex(start);
    end = getTreeIndex(end);
    long long sum = 0;
    while(start <= end) {
        if(start % 2 == 1) {
            sum += tree[start];
            start++;
        }
        if(end % 2 == 0) {
            sum += tree[end];
            end--;
        }
        start /= 2;
        end /= 2;
    }
    return sum;
}

void solve() {
    int a, b;
    long long c;
    int len = m+k;
    while(len--){
        cin>>a>>b>>c;
        if(a == 1) {
            update(b,c);
        }
        else {
            cout<<query(b,c)<<"\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    input();
    build();
    solve();

    return 0;
}