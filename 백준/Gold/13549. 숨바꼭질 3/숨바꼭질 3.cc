#include "iostream"
#include "vector"
#include "algorithm"
#include "cmath"
#include "queue"

using namespace std;

const int MAX = 1e6+1;
int n,k;
int dist[MAX];

struct cmp{
    bool operator()(pair<int,int>&a, pair<int,int>&b) {
        if(a.first == b.first) {
            return abs(k-a.second)>abs(k-b.second);
        }
        return a.first>b.first;
    }
};

int dijkstra() {
    int res = MAX;
    fill_n(dist, MAX,  MAX);
    priority_queue<pair<int,int>, vector<pair<int,int> >, cmp>pq;
    pq.push(make_pair(0,n));
    while(!pq.empty()) {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if(cur == k) {
            res = cost;
            break;
        }

        if(cur < k && dist[cur+1] > cost+1) {
            dist[cur+1] = cost+1;
            pq.push(make_pair(cost+1, cur+1));
        }
        if(cur > 0 && dist[cur-1] > cost+1) {
            dist[cur-1] = cost+1;
            pq.push(make_pair(cost+1, cur-1));
        }
        if(cur < k && dist[cur*2] > cost) {
            dist[cur*2] = cost;
            pq.push(make_pair(cost, cur*2));
        }
    }
    return res;
}

int main() {
    cin>>n>>k;
    cout<<dijkstra();
    return 0;
}