#include "iostream"
#include "vector"
#include "queue"
#include "algorithm"

using namespace std;

const int MAX = 1e4+1;
vector<pair<int,int> >map_go[MAX];
vector<pair<int,int> >map_back[MAX];
int n,m,x;

void input() {
    cin>>n>>m>>x;
    int a,b,t;
    for(int i=0;i<m;i++) {
        cin>>a>>b>>t;
        map_go[a].push_back(make_pair(b,t));
        map_back[b].push_back(make_pair(a,t));
    }
}

vector<int> dijkstra(vector<pair<int,int> >* map) {
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > >pq;
    pq.push(make_pair(0,x));
    vector<int>dist(n+1, 1e6+1);
    dist[x] = 0;
    int cost, cur;

    while(!pq.empty()) {
        cost = pq.top().first;
        cur = pq.top().second;
        pq.pop();

        for(int i=0;i<map[cur].size();i++) {
            int next = map[cur][i].first;
            int next_cost = map[cur][i].second;

            if(dist[next] > cost+next_cost) {
                dist[next] = cost+next_cost;
                pq.push(make_pair(dist[next], next));
            }
        }
    }
    return dist;
}

int main() {
    input();
    vector<int>v1 = dijkstra(map_go);
    vector<int>v2 = dijkstra(map_back);
    int max_cost = 0;
    for(int i=1;i<=n;i++) {
        if(i==x) continue;
        max_cost = max(max_cost, (v1[i]+v2[i]));
    }
    cout<<max_cost;
    return 0;
}