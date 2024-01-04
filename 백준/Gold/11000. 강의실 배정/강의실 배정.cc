#include "map"
#include "iostream"

using namespace std;

multimap<int,int>m;

void solve(multimap<int,int>::iterator it) {
    auto next = m.lower_bound(it->second);
    m.erase(it);
    if(next != m.end()) {
        solve(next);
    }
}

int main() {
    
    int n, a, b;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>a>>b;
        m.insert(make_pair(a,b));
    }

    int room=0;
    while(!m.empty()){
        solve(m.begin());
        room++;
    }
    cout<<room;
    return 0;
}