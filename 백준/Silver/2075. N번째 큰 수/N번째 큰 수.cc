#include "iostream"
#include "queue"
#include "vector"
using namespace std;

struct info{
    int num;
    int x;
    int y;
};

struct cmp {
    bool operator()(info& a, info& b) {
        return a.num < b.num;
    }
};

int arr[1500][1500];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    priority_queue<info, vector<info>, cmp>pq;
    int num, x, y;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin>>arr[i][j];
            if(i==(n-1)) {
                info inf = {arr[i][j], i, j};
                pq.push(inf);
            }
        }
    }

    if(n==1) cout<<pq.top().num;
    else {
        for (int i = n; i > 0; i--) {
            info inf = pq.top();
            num = inf.num;
            x = inf.x;
            y = inf.y;
            pq.pop();
            info cur = pq.top();

            while(i > 1) {
                num = arr[--x][y];
                if(num < cur.num) {
                    break;
                }

                i--;
            }
            inf.x = x;
            inf.num = num;
            pq.push(inf);
        }
        cout<<pq.top().num;
    }
    return 0;
}