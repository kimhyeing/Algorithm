#include "iostream"
#include "vector"
#include "algorithm"
#include "cmath"
#include "queue"

using namespace std;

const int MAX = 1e5+1;
int n,k;
int dist[MAX];

int dijkstra() {
    int res = MAX;
    fill_n(dist, MAX,  MAX);
    queue<pair<int,int> >q;
    q.push(make_pair(0,n));
    while(!q.empty()) {
        int cost = q.front().first;
        int cur = q.front().second;
        q.pop();
        if(cur == k) {
            res = cost;
            break;
        }

        if(cur < k && cur <= MAX/2 && dist[cur*2] > cost) {
            dist[cur*2] = cost;
            q.push(make_pair(cost, cur*2));
        }
        if(cur > 0 && dist[cur-1] > cost+1) {
            dist[cur-1] = cost+1;
            q.push(make_pair(cost+1, cur-1));
        }
        if(cur < k && dist[cur+1] > cost+1) {
            dist[cur+1] = cost+1;
            q.push(make_pair(cost+1, cur+1));
        }
    }
    return res;
}

int main() {
    cin>>n>>k;
    cout<<dijkstra();
    return 0;
}