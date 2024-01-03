#include "iostream"
#include "algorithm"

using namespace std;

int main() {
    int n;
    int arr[50];
    cin>>n;

    bool isZero;
    int negativeCount = 0;

    for(int i=0;i<n;i++) {
        cin>>arr[i];
        if(arr[i] == 0) isZero = true;
        if(arr[i] < 0) negativeCount++;
    }

    sort(arr,arr+n);

    int res = 0;
    int zeroIndex;
    if(negativeCount == 0) {
        for(int i=n-1;i>=0;i--) {
            if(arr[i] == 1) {
                res++;
                continue;
            }
            else if(arr[i] == 0) break;

            if(i > 0 && arr[i-1] > 1) {
                res += arr[i] * arr[i-1];
                i--;
            }
            else {
                res += arr[i];
            }
        }
    }
    else if ((negativeCount % 2) == 0) {
        int positiveIndex = n;
        for(int i=0;i<n;i++) {
            if(arr[i] >= 0) {
                positiveIndex = i;
                break;
            }

            if(i < n-1) {
                res += (arr[i] * arr[i+1]);
                i++;
            }
        }
        for(int i=n-1;i>=positiveIndex;i--) {
            if (arr[i] == 1) {
                res++;
                continue;
            } else if (arr[i] == 0) break;

            if (i > positiveIndex && arr[i-1] > 1) {
                res += arr[i] * arr[i - 1];
                i--;
            } else {
                res += arr[i];
            }
        }
    }
    else {
        int positiveIndex;
        for(int i=0;i<n;i++) {
            if(i < n-1) {
                if(arr[i+1] >= 0) {
                    if(arr[i+1] > 0) {
                        res += arr[i];
                    }
                    positiveIndex = (i+1);
                    break;
                }

                res += (arr[i] * arr[i+1]);
                i++;
            }
            else {
                res += arr[i];
                positiveIndex = i+1;
            }
        }
        for(int i=n-1;i>=positiveIndex;i--) {
            if (arr[i] == 1) {
                res++;
                continue;
            } else if (arr[i] == 0) break;

            if (i > positiveIndex && arr[i-1] > 1) {
                res += arr[i] * arr[i - 1];
                i--;
            } else {
                res += arr[i];
            }
        }
    }

    cout<<res;

    return 0;
}