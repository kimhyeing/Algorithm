#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

struct info{
    int x;
    int y;
    int dir;
};
const int WHITE = 0;
const int RED = 1;
const int BLUE = 2;
int n,k;
int board[12][12];
int dirx[4] = {0,0,-1,1};
int diry[4] = {1,-1,0,0};
vector<info>list;
vector<int>position[12][12];

void input() {
    cin>>n>>k;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin>>board[i][j];
        }
    }
    int a,b,d;
    for(int i=0;i<k;i++) {
        cin>>a>>b>>d;
        info t = {a-1,b-1,d-1};
        list.push_back(t);
        position[a-1][b-1].push_back(i);
    }
}

bool solve() {
    int newx, newy, newdir, op, index, start;

    for(int idx = 0; idx<list.size();idx++) {
        info h = list[idx];
        newx = h.x + dirx[h.dir];
        newy = h.y + diry[h.dir];
        if(newx < 0 || newy < 0 || newx >= n || newy >= n) {
            op = BLUE;
        }
        else op = board[newx][newy];
        if(op == BLUE) {
            if(h.dir == 0) newdir = 1;
            else if(h.dir == 1) newdir = 0;
            else if(h.dir == 2) newdir = 3;
            else newdir = 2;
            list[idx].dir = newdir;
            newx = h.x + dirx[newdir];
            newy = h.y + diry[newdir];
            if(newx < 0 || newy < 0 || newx >= n || newy >= n) continue;
            op = board[newx][newy];
            if(op == BLUE) continue;
        }

        if(op == WHITE) {
            auto iter = find(position[h.x][h.y].begin(), position[h.x][h.y].end(), idx);
            start = iter-position[h.x][h.y].begin();
            for(int i=start; i<position[h.x][h.y].size();i++) { //추가
                index = position[h.x][h.y][i];
                list[index].x = newx; // 기존 정보 변경
                list[index].y = newy;
                position[newx][newy].push_back(index);
            }
            position[h.x][h.y].erase(iter, position[h.x][h.y].end()); // 기존 것 삭제
            if(position[newx][newy].size() >= 4) {
                return true;
            }
        }
        else {
            auto iter = find(position[h.x][h.y].begin(), position[h.x][h.y].end(), idx);
            start = iter-position[h.x][h.y].begin();
            for(int i=(int)(position[h.x][h.y].size()-1); i>=start;i--) { //추가
                index = position[h.x][h.y][i];
                list[index].x = newx; // 기존 정보 변경
                list[index].y = newy;
                position[newx][newy].push_back(index);
            }
            position[h.x][h.y].erase(iter, position[h.x][h.y].end()); // 기존 것 삭제
            if(position[newx][newy].size() >= 4) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    int result = -1;
    for(int i=1;i<=1000;i++) {
        if(solve()) {
            result = i;
            break;
        }
    }
    cout<<result;
    return 0;
}