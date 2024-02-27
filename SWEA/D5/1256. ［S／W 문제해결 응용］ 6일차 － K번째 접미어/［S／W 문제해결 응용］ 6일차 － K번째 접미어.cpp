#include<iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int k;
string str;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int test_case;
    int T;

    cin>>T;

    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin>>k>>str;
        int len = str.length();
        string substr;
        vector<string>v;
        for(int i=0;i<len;i++) {
            substr = str.substr(i, len-i);
            v.emplace_back(substr);
        }
        sort(v.begin(), v.end());
        cout<<"#"<<test_case<<" "<<v[k-1]<<"\n";

    }
    return 0;
}