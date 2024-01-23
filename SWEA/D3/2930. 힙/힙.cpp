#include<iostream>
#include <queue>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        priority_queue<int>pq;
        int n, op, x;
        cin>>n;
        cout<<"#"<<test_case<<" ";
        while(n--) {
            cin >> op;
            if (op == 1) {
                cin >> x;
                pq.push(x);
            } else {
                if(pq.empty()) {
                    cout<<-1<<" ";
                }
                else {
                    cout<<pq.top()<<" ";
                    pq.pop();
                }
            }
        }
        cout<<"\n";
    }
    return 0;
}