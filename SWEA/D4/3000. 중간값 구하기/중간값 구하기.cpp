#include<iostream>
#include <queue>

using namespace std;

const int REMINDER = 20171109;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case, T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        priority_queue<int>max_heap;
        priority_queue<int, vector<int>, greater<int> >min_heap;
        int n, a, root, res = 0, x, y;
        cin>>n>>a;
        root = a;
        max_heap.push(a);
        min_heap.push(a);
        cout<<"#"<<test_case<<" ";
        while(n--) {
            cin>>x>>y;
            if(x>root && y>root) {
                min_heap.pop();
                min_heap.push(x);
                min_heap.push(y);
                root = min_heap.top();

                max_heap.push(root);
            }
            else if(x<root && y<root) {
                max_heap.pop();
                max_heap.push(x);
                max_heap.push(y);
                root = max_heap.top();

                min_heap.push(root);
            }
            else {
                if(y>x) {
                    min_heap.push(y);
                    max_heap.push(x);
                }
                else {
                    min_heap.push(x);
                    max_heap.push(y);
                }
            }
            res = (res+root)%REMINDER;
        }

        cout<<res<<"\n";
    }
    return 0;
}