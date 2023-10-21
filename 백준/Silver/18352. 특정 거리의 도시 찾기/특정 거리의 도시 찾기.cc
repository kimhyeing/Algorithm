#include "iostream"
#include "queue"
#include "vector"

using namespace std;

const int MAX = 3*(1e5)+1;
const int INF = INT32_MAX;
int n,m,k,x;
int dist[MAX];
vector<int> v[MAX];

void input() {
    cin>>n>>m>>k>>x;
    int a,b;
    for(int i=0;i<m;i++) {
        cin>>a>>b;
        v[a].push_back(b);
    }
    fill_n(&dist[0], n+1, INF);
}

void solve() {
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > >pq;
    pq.push(make_pair(0, x));
    while(!pq.empty()) {
        int cur = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        for(int i=0;i<v[cur].size();i++) {
            int new_cur = v[cur][i];
            int new_cost = cost+1;
            if(dist[new_cur] > new_cost) {
                dist[new_cur] = new_cost;
                pq.push(make_pair(new_cost, new_cur));
            }
        }
    }
}

void print() {
    bool exec = false;
    for(int i=1;i<=n;i++) {
        if(i==x) continue;
        if(dist[i] == k) {
            exec = true;
            cout<<i<<"\n";
        }
    }
    if(!exec) cout<<"-1";
}

int main() {
    input();
    solve();
    print();
    return 0;
}