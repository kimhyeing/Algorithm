#include<iostream>
#include <vector>
#include <set>

using namespace std;

const int MAX = 1e4;
int parent[MAX];

int get_size(int n, vector<int> child[MAX+1]) {
    if(child[n].empty()) return 1;

    if(child[n].size() == 2) {
        return get_size(child[n][0], child) + get_size(child[n][1], child) + 1;
    }
    return get_size(child[n][0], child) + 1;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case, T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        vector<int>child[MAX+1];

        int v, e, x, y, a, b;
        set<int>s;
        cin>>v>>e>>x>>y;
        for(int i=0;i<e;i++) {
            cin>>a>>b;
            parent[b] = a;
            child[a].push_back(b);
        }
        cout<<"#"<<test_case<<" ";

        int p = 0;
        s.insert(x);

        while(x!=1) {
            p = parent[x];
            x = p;
            s.insert(x);
        }

        while(y!=x) {
            p = parent[y];
            y = p;
            if(s.find(y) != s.end()) {
                break;
            }
        }
        cout<<y<<" "<<get_size(y, child);

        cout<<"\n";

    }
    return 0;
}