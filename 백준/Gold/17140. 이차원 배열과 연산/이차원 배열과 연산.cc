#include "iostream"
#include "vector"
#include "algorithm"
#include "map"

using namespace std;

int x, y, k, r=3, c=3;
vector<vector<int> >A(3);

void input() {
    cin>>x>>y>>k;
    x--; y--;
    int a;
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            cin>>a;
            A[i].push_back(a);
        }
    }
}

bool cmp(pair<int,int>a, pair<int,int> b) {
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

void sort_R() {
    vector<vector<int> >temp = A;
    vector<vector<pair<int, int> > >temp_cnt;
    A.clear();
    A.resize(r);
    int max_C = 0;
    for(int i=0;i<r;i++) {
        map<int, int>m;
        vector<pair<int,int> >ttemp;
        for(int j=0;j<c;j++) {
            auto iter = m.find(temp[i][j]);
            if(temp[i][j] == 0) continue;
            if(iter != m.end()) {
                iter->second = iter->second+1;
            }
            else {
                m.insert(make_pair(temp[i][j], 1));
            }
        }
        for(auto mm: m) {
            ttemp.push_back(mm);
        }
        max_C = max(max_C, (int)ttemp.size()*2);
        sort(ttemp.begin(), ttemp.end(), cmp);
        temp_cnt.push_back(ttemp);
    }
    c = max_C;
    if(c > 100) c = 100;

    for(int i=0;i<r;i++) {
        int cur_len = temp_cnt[i].size();
        for(int j=0;j<cur_len;j++) {
            A[i].push_back(temp_cnt[i][j].first);
            A[i].push_back(temp_cnt[i][j].second);
        }
        for(int j=cur_len;j<c;j++) {
            A[i].push_back(0);
        }
    }
}

void sort_C() {
    vector<vector<int> >temp = A;
    vector<vector<pair<int, int> > >temp_cnt;
    A.clear();
    int max_R = 0;
    for(int j=0;j<c;j++) {
        map<int, int>m;
        vector<pair<int,int> >ttemp;
        for(int i=0;i<r;i++) {
            auto iter = m.find(temp[i][j]);
            if(temp[i][j] == 0) continue;
            if(iter != m.end()) {
                iter->second = iter->second+1;
            }
            else {
                m.insert(make_pair(temp[i][j], 1));
            }
        }
        for(auto mm: m) {
            ttemp.push_back(mm);
        }
        max_R = max(max_R, (int)ttemp.size()*2);
        sort(ttemp.begin(), ttemp.end(), cmp);
        temp_cnt.push_back(ttemp);
    }
    r = max_R;
    if(r > 100) r = 100;
    A.resize(r);
    for(int j=0;j<temp_cnt.size();j++) {
        int cur_len = temp_cnt[j].size();
        int idx = 0;
        for(int i=0;i<cur_len;i++) {
            A[idx].push_back(temp_cnt[j][i].first);
            A[idx+1].push_back(temp_cnt[j][i].second);
            idx+=2;
        }
        cur_len *= 2;
        for(int i=cur_len;i<r;i++) {
            A[i].push_back(0);
        }
    }
}

int solve() {
    int ktime = 0;
    while(x>=r || y>=c || A[x][y] != k) {
        if(ktime > 100) break;
        if(r>=c) {
            sort_R();
        }
        else sort_C();
        ktime++;
    }
    if(ktime > 100) return -1;
    return ktime;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    cout<<solve();

    return 0;
}