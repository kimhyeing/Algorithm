#include "iostream"
#include "queue"
#include "vector"
#include "algorithm"

using namespace std;

const int MAX = 801;
int n,e,v1,v2;
vector<pair<int,int> >graph[MAX];
vector<pair<int,int> > root1;
vector<pair<int,int> > root2;

void input() {
    cin>>n>>e;
    int a,b,c;
    for(int i=0;i<e;i++) {
        cin>>a>>b>>c;
        graph[a].push_back(make_pair(b,c));
        graph[b].push_back(make_pair(a,c));
    }
    cin>>v1>>v2;
    root1.push_back(make_pair(1,v1));
    root1.push_back(make_pair(v1,v2));
    root1.push_back(make_pair(v2,n));
    root2.push_back(make_pair(1,v2));
    root2.push_back(make_pair(v2,v1));
    root2.push_back(make_pair(v1,n));
}

long long int dijkstra(int start, int end) {
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int,int> > >pq;
    pq.push(make_pair(0,start));
    vector<int>dist(n+1, INT32_MAX);
    dist[start] = 0;
    int cost, cur;
    bool success = false;
    while(!pq.empty()) {
        cost = pq.top().first;
        cur = pq.top().second;
        pq.pop();
        if(cur == end) success = true;
        for(int i=0;i<graph[cur].size();i++) {
            int next = graph[cur][i].first;
            int next_cost = graph[cur][i].second;

            if(dist[next] > cost+next_cost) {
                dist[next] = cost+next_cost;
                pq.push(make_pair(dist[next], next));
            }
        }
    }
    if(success) return dist[end];
    return -1;
}

long long int getCost(vector<pair<int,int> >& v) {
    long long int res = 0, temp;
    int start, end;
    for(int i=0;i<3;i++) {
        start = v[i].first;
        end = v[i].second;
        temp = dijkstra(start, end);
        if(temp == -1) return -1;
        res += temp;
    }
    return res;
}
long long int solve() {
    long long int r1, r2;
    r1 = getCost(root1);
    r2 = getCost(root2);
    if(r1 == -1 && r2 == -1) return -1;
    return min(r1, r2);
}

int main() {
    input();
    cout<<solve();
    return 0;
}