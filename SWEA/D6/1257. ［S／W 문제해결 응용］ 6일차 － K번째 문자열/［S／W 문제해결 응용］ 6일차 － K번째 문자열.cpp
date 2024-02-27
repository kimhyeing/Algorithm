#include<iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int test_case;
    int T;

    cin>>T;
    int k;
    string str;

    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin>>k>>str;
        int len = str.length();
        string substr;
        vector<string>v;
        unordered_set<string>us;
        for(int i=0;i<len;i++) {
            for(int j=i+1;j<=len;j++) {
                substr = str.substr(i, j-i);
                if(us.find(substr) == us.end()) {
                    v.emplace_back(substr);
                    us.insert(substr);
                }
            }
        }
        sort(v.begin(), v.end());

        cout<<"#"<<test_case<<" ";
        if(k > v.size() || k < 1) {
            cout<<"none\n";
        } else {
            cout<<v[k-1]<<"\n";
        }
    }
    return 0;
}