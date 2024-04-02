#include "iostream"
#include "vector"
#include "cmath"
#include "algorithm"

using namespace std;

int n,m;
vector<pair<int,int> >home;
vector<pair<int,int> >chicken;
vector<pair<int,int> >selected_chicken;
int chicken_size, home_size, res = INT32_MAX;
bool selected[13];

void input() {
    cin >> n >> m;
    int a;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin>>a;
            if(a==1) {
                home.push_back(make_pair(i,j));
            }
            else if(a==2) {
                chicken.push_back(make_pair(i,j));
            }
        }
    }
    home_size = home.size();
    chicken_size = chicken.size();
}

int get_sum(){
    int sum = 0;
    for(int i=0;i<home_size;i++) {
        int temp_d = INT32_MAX;
        for(int j=0;j<selected_chicken.size();j++) {
            temp_d = min(temp_d, abs(selected_chicken[j].first-home[i].first) + abs(selected_chicken[j].second-home[i].second));
        }
        sum+=temp_d;
    }
    return sum;
}

void solve(int idx, int cnt) {
    if(cnt == m) {
        res = min(res, get_sum());
        return;
    }

    for(int i=idx;i<chicken_size;i++) {
        if(selected[i]) continue;
        selected[i] = true;
        selected_chicken.push_back(chicken[i]);
        solve(i, cnt+1);
        selected[i] = false;
        selected_chicken.pop_back();
    }
}

int main() {
    input();
    solve(0,0);
    cout<<res;
    return 0;
}