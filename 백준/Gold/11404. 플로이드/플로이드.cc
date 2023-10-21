#include "iostream"
#include "algorithm"

using namespace std;

const int MAX = 101;
const int INF = INT32_MAX;
long long dist[MAX][MAX];
int n,m;

void input() {
    cin>>n>>m;
    fill(&dist[1][1], &dist[n][n], INF);

    long long a,b,c;
    for(int i=0;i<m;i++) {
        cin>>a>>b>>c;
        dist[a][b] = min(dist[a][b], c);
    }
}

void solve(){
    for(int k=1;k<=n;k++) {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                if((dist[i][k]+dist[k][j]) < dist[i][j])
                    dist[i][j] = (dist[i][k]+dist[k][j]);
            }
        }
    }
}

void print() {
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(i==j || dist[i][j] >= INT32_MAX) cout<<"0 ";
            else cout<<dist[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main() {
    input();
    solve();
    print();
    return 0;
}