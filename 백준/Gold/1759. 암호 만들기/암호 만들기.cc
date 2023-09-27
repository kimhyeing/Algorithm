#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;

int l,c;
char alpha[15];
bool selected[15];
vector<char>v;

void input() {
    cin>>l>>c;
    for(int i=0;i<c;i++) {
        cin>>alpha[i];
    }
    sort(alpha, alpha+c);
}

bool check() {
    int m_count = 0, j_count = 0;
    for(char i : v) {
        if(m_count >= 1 && j_count >= 2) return true;

        if(i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u') {
            m_count++;
        }
        else {
            j_count++;
        }
    }
    if(m_count>=1 && j_count>=2) return true;
    return false;
}

void print() {
    for(char i : v) {
        cout<<i;
    }
    cout<<"\n";
}

void solve(int idx, int cnt) {
    if(l == cnt && check()) {
        print();
        return;
    }

    for(int i=idx;i<c;i++) {
        if(selected[i]) continue;
        v.push_back(alpha[i]);
        selected[i] = true;
        solve(i, cnt+1);
        selected[i] = false;
        v.pop_back();
    }
}
int main() {
    input();
    solve(0,0);

    return 0;
}