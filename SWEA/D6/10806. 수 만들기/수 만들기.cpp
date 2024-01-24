#include<iostream>
#include <queue>
#include <vector>

using namespace std;

#define pii pair<int,int>

struct cmp{
    bool operator()(pii& a, pii& b) {
        if(a.first == b.first)
            return a.second > b.second;
        return a.first > b.first;
    }
};
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case, T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        priority_queue<pii, vector<pii>, cmp>pq;
        vector<int>v;
        int n, k, a, c, r;
        cin>>n;

        int min_num = 1000000001;
        for(int i=0;i<n;i++) {
            cin>>a;
            if(a < min_num) {
                min_num = a;
            }
            v.push_back(a);
        }
        cin>>k;

        pq.push(make_pair(0,k));

        while(true) {
            c = pq.top().first;
            r = pq.top().second;
            if(!r) {
                break;
            }
            pq.pop();

            for(int i=0;i<n;i++) {
                a = v[i];
                pq.push(make_pair(c+(r%a), r/a));
            }
        }

        cout<<"#"<<test_case<<" "<<pq.top().first<<"\n";
    }
    return 0;
}