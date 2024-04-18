#include "iostream"
#include "queue"
#include "vector"
#include "algorithm"

using namespace std;

int dirx[4] = {0,1, 0,-1};
int diry[4] = {1,0, -1, 0};
int n;
int arr[125][125];
int dp[125][125];
struct info{
    int cost;
    int x;
    int y;
};
struct cmp {
    bool operator()(info& a, info& b) {
        if(a.cost == b.cost) {
            if(a.x == b.x) {
                return a.y > b.y;
            }
            return a.x > b.x;
        }
        return a.cost > b.cost;
    }
};


int dijkstra() {
    fill(&dp[0][0], &dp[n-1][n], INT32_MAX);
    priority_queue<info, vector<info>, cmp>pq;
    info dt = {arr[0][0], 0, 0};
    dp[0][0] = arr[0][0];
    pq.push(dt);
    int x, y, cost, newx, newy, newcost;
    while(!pq.empty()) {
        x = pq.top().x;
        y = pq.top().y;
        cost = pq.top().cost;
        pq.pop();
        for(int i=0;i<4;i++) {
            newx = x + dirx[i];
            newy = y + diry[i];

            if(newx < 0 || newy < 0 || newx >= n || newy >= n) continue;
            newcost = cost + arr[newx][newy];
            if(dp[newx][newy] > newcost) {
                dp[newx][newy] = newcost;
                dt.cost = newcost;
                dt.x = newx;
                dt.y = newy;
                pq.push(dt);
            }
        }
    }
    return dp[n-1][n-1];
}

int main() {
    int idx = 1;
    while(true) {
        cin >> n;
        if(n==0) break;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> arr[i][j];
            }
        }
        cout<<"Problem "<<idx<<": "<<dijkstra()<<"\n";
        idx++;
    }
    return 0;
}