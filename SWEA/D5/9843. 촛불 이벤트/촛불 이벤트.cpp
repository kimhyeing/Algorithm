#include<iostream>

using namespace std;

int solve(long long x) {
    long long left = 1;
    long long right = 10000000000;
    long long mid;
    long long res;
    bool isSuccess = false;
    while(left <= right) {
        mid = (left+right)/2;
        res = mid*(mid+1);
        if((2*x) == res) {
            isSuccess = true;
            break;
        }
        else if((2*x) < res) {
            right = mid-1;
        }
        else {
            left = mid+1;
        }
    }

    if(isSuccess) {
        return mid;
    }
    else return -1;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int test_case;
    int T;
    cin>>T;
    long long n;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin>>n;
        cout<<"#"<<test_case<<" "<<solve(n)<<"\n";
    }
    return 0;
}