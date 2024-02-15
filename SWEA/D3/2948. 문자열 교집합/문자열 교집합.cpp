#include<iostream>
#include <unordered_set>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int test_case;
    int T;

    cin>>T;
    int n,m, cnt;
    string str;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cnt = 0;
        cin>>n>>m;
        unordered_set<string>s;

        for(int i=0;i<n;i++) {
            cin>>str;
            s.insert(str);
        }
        for(int j=0;j<m;j++) {
            cin>>str;
            if(s.find(str) != s.end()) {
                cnt++;
            }
        }
        cout<<"#"<<test_case<<" "<<cnt<<"\n";
    }
    return 0;
}