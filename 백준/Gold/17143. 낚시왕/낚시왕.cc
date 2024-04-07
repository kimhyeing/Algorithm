#include "iostream"
#include "algorithm"
#include "map"
#include "vector"

using namespace std;

struct Shark{
    int idx;
    int x;
    int y;
    int s;
    int d;
    int z;
};
int R,C,M, k_idx, result;
Shark sea[101][101];
Shark empty_shark = {0,0,0,0,0,0};
map<int, Shark>um;

void input() {
    int r,c,s,d,z;
    cin>>R>>C>>M;
    for(int i=0;i<M;i++) {
        cin>>r>>c>>s>>d>>z;
        Shark sh = {i,r,c,s,d-1,z};
        sea[r][c] = sh;
        um.insert(make_pair(i,sh));
    }
}

void king_move() {
    k_idx++;
    for(int i=1;i<=R;i++) {
        if(sea[i][k_idx].z > 0) {
            result += sea[i][k_idx].z;
            um.erase(sea[i][k_idx].idx);
            sea[i][k_idx] = empty_shark;
            break;
        }
    }
}

void shark_move() {
    int x, y, s,d,z, start, distance;
    Shark temp_sea[101][101];
    fill(&temp_sea[1][1], &temp_sea[R][C+1], empty_shark);
    vector<int>erase_idx;
    for(auto& shark: um){
        Shark sh = shark.second;
        x = sh.x;
        y = sh.y;
        if(sh.z < 1) continue;
        s = sh.s;
        d = sh.d;
        z = sh.z;

        if(d<=1) {
            if(d==1) start = x-2;
            else start = R-x-1;
            distance = start+s;
            if(distance < (R-1)) {
                if(d==1) x = distance+2;
                else x = R-distance-1;
            }
            else {
                if((distance/(R-1))%2) { // 다른 방향
                    if(d==1) d=0;
                    else d=1;
                }
                if(d==1) x = 2+(distance%(R-1));
                else x = (R-1)-(distance%(R-1));
            }
        }
        else {
            if(d==2) start = y-2;
            else start = C-y-1;
            distance = start+s;
            if(distance < (C-1)) {
                if(d==2) y = distance+2;
                else y = C-distance-1;
            }
            else {
                if((distance/(C-1))%2) { // 다른 방향
                    if(d==2) d=3;
                    else d=2;
                }
                if(d==2) y = 2+(distance%(C-1));
                else y = (C-1)-(distance%(C-1));
            }
        }

        if(temp_sea[x][y].z == 0) { // 신규
            sh.x = x; sh.y = y; sh.d = d;
            shark.second = sh;
            temp_sea[x][y] = sh;
        } else if(temp_sea[x][y].z < z) { // 이미 있는데, 현재 상어가 더 큼
            sh.x = x; sh.y = y; sh.d = d;
            shark.second = sh;
            erase_idx.push_back(temp_sea[x][y].idx);
            temp_sea[x][y] = sh;
        }
        else { // 현재 상어를 삭제
            erase_idx.push_back(sh.idx);
        }
    }


    for(int i : erase_idx) {
        um.erase(i);
    }
    copy(&temp_sea[1][1], &temp_sea[R][C+1], &sea[1][1]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    if(!um.empty()) {
        while (k_idx != C) {
            king_move();
            shark_move();
        }
    }
    cout<<result;
    return 0;
}