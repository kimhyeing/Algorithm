#include<iostream>

using namespace std;

long long int p[101];

int main() {
	int t, n;
	cin >> t;
	p[1] = p[2] = p[3] = 1;
	p[4] = 2;
	while (t--) {
		cin >> n;
		for (int i = 5; i <= n; i++) {
			if(p[i] == 0) p[i] = p[i - 1] + p[i - 5];
		}
		cout << p[n] << "\n";
	}
	return 0;
}