#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

int n,m,k;
int A[12][12];
int land[12][12];
vector<int>tree[11][11];
int dead_tree[11][11];
int dirx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int diry[8] = {-1,0,1,-1,1,-1,0,1};

void input() {
    cin>>n>>m>>k;
    int x,y,age;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cin>>A[i][j];
        }
    }
    for(int i=1;i<=m;i++) {
        cin>>x>>y>>age;
        tree[x][y].push_back(age);
    }
}

void set_dead(int x, int y, int t) {
    int res = 0;
    for(int i=t;i<tree[x][y].size();i++) {
        res += (tree[x][y][i]/2);
    }
    dead_tree[x][y] = res;
}

void spring() {
    int temp;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(!tree[i][j].empty()) {
                sort(tree[i][j].begin(), tree[i][j].end());
                temp = land[i][j];
                for(int t=0;t<tree[i][j].size();t++) {
                    if(temp < tree[i][j][t]) {
                        set_dead(i,j,t);
                        tree[i][j].erase(tree[i][j].begin()+t, tree[i][j].end());
                        break;
                    }
                    temp -= tree[i][j][t]; // 양분 먹기
                    tree[i][j][t]++; // 트리 나이 1 증가
                }
                land[i][j] = temp;
            }
        }
    }
}

void summer() {
    for(int i=1;i<=n;i++) {
        for (int j = 1; j <= n; j++) {
            land[i][j] += dead_tree[i][j];
            dead_tree[i][j] = 0;
        }
    }
}

void spread(int x, int y) {
    int newx, newy;
    for(int i=0;i<8;i++) {
        newx = x+dirx[i];
        newy = y+diry[i];
        if(newx < 1 || newy < 1 || newx > n || newy > n) continue;
        tree[newx][newy].push_back(1);
    }
}

void fall() {
    for(int i=1;i<=n;i++) {
        for (int j = 1; j <= n; j++) {
            for(int t=0;t<tree[i][j].size();t++) {
                if(tree[i][j][t] != 0 && (tree[i][j][t]%5) == 0) {
                    spread(i,j);
                }
            }
        }
    }
}

void winter() {
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            land[i][j] += A[i][j];
        }
    }
}

int get_tree() {
    int res = 0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            res += tree[i][j].size();
        }
    }
    return res;
}

int main() {
    fill(&land[1][1], &land[11][11], 5);
    input();

    for(int i=0;i<k;i++) {
        spring();
        summer();
        fall();
        winter();
    }
    cout<<get_tree();

    return 0;
}