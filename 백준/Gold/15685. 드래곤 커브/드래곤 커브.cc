#include "iostream"
#include "stack"
#include "vector"
#include "set"

using namespace std;

struct dragon{
    int x;
    int y;
    int d;
};
int n;
vector<dragon>v;
vector<int>gen;
bool visited[101][101];
int diry[4] = {0, -1, 0, 1};
int dirx[4] = {1, 0, -1, 0};
set<pair<int, int> >dot_list;

void input() {
    cin>>n;
    int x,y,d,g;
    for(int i=0;i<n;i++) {
        cin>>x>>y>>d>>g;
        dragon dr = {x,y,d};
        gen.push_back(g);
        v.push_back(dr);
    }
}

dragon get_dragon(int x, int y, int d) {
    dragon dr = {x,y,d};
    return dr;
}

void curve(int x, int y, int d, int g) {
    stack<dragon>origin;
    origin.push(get_dragon(x,y,d));
    origin.push(get_dragon(x+dirx[d], y+diry[d], d));
    int newd, newx, newy, prex, prey;
    visited[x][y] = true;
    visited[x+dirx[d]][y+diry[d]] = true;
    dot_list.insert(make_pair(x,y));
    dot_list.insert(make_pair(x+dirx[d], y+diry[d]));
    while(g) {
        g--;
        stack<dragon>temp = origin;
        dragon cur_dragon = temp.top();
        prex = cur_dragon.x;
        prey = cur_dragon.y;
        while(temp.size() > 1) {
            temp.pop();
            newd = (cur_dragon.d + 1)%4;
            newx = prex + dirx[newd];
            newy = prey + diry[newd];
            visited[newx][newy] = true;
            dot_list.insert(make_pair(newx,newy));
            origin.push(get_dragon(newx, newy, newd));

            prex = newx;
            prey = newy;
            cur_dragon = temp.top();
        }
    }
}
void calculate() {
    for(int i=0;i<n;i++) {
        curve(v[i].x, v[i].y, v[i].d, gen[i]);
    }
}

int get_result() {
    int x, y, result = 0;
    for(auto dot: dot_list) {
        x = dot.first;
        y = dot.second;
        if(y+1 > 100 || x+1 > 100) continue;
        if(visited[x][y] && visited[x+1][y] && visited[x][y+1] && visited[x+1][y+1]) {
            result++;
        }
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    input();
    calculate();
    cout<<get_result();
    return 0;
}