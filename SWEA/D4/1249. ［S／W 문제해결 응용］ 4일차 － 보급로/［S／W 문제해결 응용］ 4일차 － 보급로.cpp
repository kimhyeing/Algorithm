#include<iostream>
#include <queue>
#include <vector>

using namespace std;

int n;
int graph[100][100];
int dist[100][100];
int dirx[4] = {-1,0,1,0};
int diry[4] = {0, 1, 0,-1};

struct Node{
    int x;
    int y;
    int cost;
};

void input() {
    cin>>n;
    char c;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin>>c;
            graph[i][j] = c-'0';
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            dist[i][j] = INT32_MAX;
        }
    }
}

struct cmp {
    bool operator()(Node& a, Node& b) {
        if(a.cost == b.cost) {
            if(a.x == b.x) {
                return a.y < b.y;
            }
            return a.x < b.x;
        }
        return a.cost > b.cost;
    }
};

int solve() {
    priority_queue<Node, vector<Node>, cmp>pq;
    Node node = {0,0,0};
    pq.push(node);
    dist[0][0] = 0;
    int cost, x, y, newx, newy, new_cost;
    while(!pq.empty()) {
        cost = pq.top().cost;
        x = pq.top().x;
        y = pq.top().y;
        pq.pop();

        if(dist[x][y] < cost) continue;

        for(int i=0;i<4;i++) {
            newx = x+dirx[i];
            newy = y+diry[i];

            if(newx < 0 || newx >= n || newy < 0 || newx >= n) {
                continue;
            }

            new_cost = cost + graph[newx][newy];
            if(dist[newx][newy] > new_cost) {
                dist[newx][newy] = new_cost;
                node.x = newx;
                node.y = newy;
                node.cost = new_cost;
                pq.push(node);
            }
        }
    }
    return dist[n-1][n-1];
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int test_case;
    int T;
    cin>>T;

    for(test_case = 1; test_case <= T; ++test_case)
    {
        input();
        cout<<"#"<<test_case<<" "<<solve()<<"\n";
    }
    return 0;
}