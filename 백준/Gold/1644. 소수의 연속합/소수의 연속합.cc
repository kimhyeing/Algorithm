#include "iostream"
#include "cstring"
#include "vector"

using namespace std;

const int MAX = 4000000;
bool isPrime[MAX+1];
vector<int>prime;
int n;
void setPrime() {
    prime.push_back(0);
    memset(isPrime, true, sizeof(bool)*(n+1));
    for(int i=2;i<=n;i++) {
        if(isPrime[i]) {
            prime.push_back(i);
            for(int j=i*2;j<=n;j+=i) {
                isPrime[j] = false;
            }
        }
    }
}

int main() {
    cin>>n;
    setPrime();
    int start = 0, end = 1, cnt = 0, sum = prime[1];
    int len = prime.size();
    while(start<=end) {
        if(sum == n) {
            cnt++;
            if((end+1) >= len || (start+1) >= len) break;
            sum += prime[++end];
            sum -= prime[++start];
        }
        else if(sum < n) {
            if((end+1) >= len) break;
            sum += prime[++end];
        }
        else {
            if((start+1) >= len) break;
            sum -= prime[++start];
        }
    }
    cout<<cnt<<"\n";
    return 0;
}