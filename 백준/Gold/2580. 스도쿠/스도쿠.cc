#include "iostream"
#include "vector"

using namespace std;

int map[9][9];
int line_x[9];
int line_y[9];
int area[3][3];
vector<pair<int,int> >v;

void print_binary(int a) {
    for(int i=8;i>=0;i--) {
        cout<<((a>>i)&1);
    }
    cout<<"\n";
}

void print() {
    for(int i=0;i<9;i++) {
        for(int j=0;j<9;j++){
            cout<<map[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void input() {
    for(int i=0;i<9;i++) {
        for(int j=0;j<9;j++) {
            cin>>map[i][j];
            if(map[i][j] == 0){
                v.push_back(make_pair(i,j));
            }
            else {
                line_x[i] |= (1<<(map[i][j]-1));
                line_y[j] |= (1<<(map[i][j]-1));
                area[i/3][j/3] |= (1<<(map[i][j]-1));
            }
        }
    }
}

vector<int> check(int i, int j) {
    vector<int>res;
    int line_x_bias = ~line_x[i];
    int line_y_bias = ~line_y[j];
    int area_bias = ~area[i/3][j/3];
    int temp = line_x_bias & line_y_bias & area_bias;
    if(temp == 0) return res;
    for(int i=0;i<=8;i++) {
        if((temp>>i)&1) {
            res.push_back(i);
        }
    }
    return res;
}

bool dfs(int idx) {
    if(idx == v.size()) return true;

    int x = v[idx].first;
    int y = v[idx].second;

    vector<int>_v = check(x,y);
    if(_v.empty()) return false;

    for(int i=0;i<_v.size();i++) {
        line_x[x] |= (1<<_v[i]);
        line_y[y] |= (1<<_v[i]);
        area[x/3][y/3] |= (1<<_v[i]);
        map[x][y] = _v[i]+1;

        if(dfs(idx+1)) return true;

        line_x[x] &= ~(1<<_v[i]);
        line_y[y] &= ~(1<<_v[i]);
        area[x/3][y/3] &= ~(1<<_v[i]);
    }
    return false;
}

int main() {
    input();
    dfs(0);
    print();
    return 0;
}