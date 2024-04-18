#include "iostream"
#include "unordered_set"
#include "string"

using namespace std;

int main() {
    string str;
    unordered_set<string>s;
    cin>>str;
    int len = str.size();
    for(int i=0;i<len;i++) {
        for(int j=1;j<=(len-i);j++) {
            if(s.find(str.substr(i,j)) == s.end()) {
                s.insert(str.substr(i,j));
            }
        }
    }
    cout<<s.size();
    return 0;
}