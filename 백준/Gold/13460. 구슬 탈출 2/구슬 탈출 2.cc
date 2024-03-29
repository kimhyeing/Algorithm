#include "iostream"
#include "algorithm"
#include "cmath"

using namespace std;

int n,m;
char arr[11][11];
pair<int, int>bpos;
pair<int, int>rpos;
int dirx[4] = {-1, 0, 1, 0};
int diry[4] = {0, 1, 0, -1};

void input() {
    cin>>n>>m;
    char c;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>arr[i][j];
            if(arr[i][j] == 'B') {
                bpos = make_pair(i,j);
            }
            else if(arr[i][j] == 'R') {
                rpos = make_pair(i,j);
            }
        }
    }
}

int min_count = INT32_MAX;
void dfs(int dir, int c, pair<int,int>b, pair<int,int>r, pair<int, int>preb, pair<int,int>prer) {
    if(c>10) return;

    int bx, by, rx, ry;
    bool isAgain, success, isEnd;
    for(int i=0;i<4;i++) {
        if(i == dir) continue;
        bx = b.first, by = b.second, rx = r.first, ry = r.second;
        isAgain = success = isEnd = false;
        while(arr[bx+dirx[i]][by+diry[i]] != '#') {
            bx += dirx[i];
            by += diry[i];
            if (arr[bx][by] == 'O') {
                isEnd = true;
                break;
            }
            if(bx == rx && by == ry) {
                bx -= dirx[i];
                by -= diry[i];
                isAgain = true;
                break;
            }
        }
        if(isEnd) continue;
        while(arr[rx+dirx[i]][ry+diry[i]] != '#') {
            rx += dirx[i];
            ry += diry[i];
            if(arr[rx][ry] == 'O') {
                if(!isAgain) {
                    min_count = min(min_count, c);
                    return;
                }
                success = true;
                break;
            }
            if(rx == bx && ry == by) {
                rx -= dirx[i];
                ry -= diry[i];
                break;
            }
        }
        if(isAgain) {
            while(arr[bx+dirx[i]][by+diry[i]] != '#') {
                bx += dirx[i];
                by += diry[i];
                if (arr[bx][by] == 'O') {
                    isEnd = true;
                    break;
                }
                if(bx == rx && by == ry) {
                    bx -= dirx[i];
                    by -= diry[i];
                    break;
                }
            }
            if(isEnd) continue;
            if(success) {
                min_count = min(min_count, c);
                return;
            }
        }
        if(b.first != bx || b.second != by || r.first != rx || r.second != ry) {
            if(preb.first != bx || preb.second != by || prer.first != rx || prer.second != ry) {
                dfs(i, c + 1, make_pair(bx, by), make_pair(rx, ry), b, r);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    input();
    dfs(-1, 1, bpos, rpos, make_pair(-1, -1), make_pair(-1, -1));
    if(min_count == INT32_MAX) {
        cout<<-1;
    }
    else cout<<min_count;
    return 0;
}