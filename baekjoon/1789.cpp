#include<iostream>

using namespace std;

int main() {
	long long int s, n = 1;
	cin >> s;
	while (true) {
		if (n * (n + 1) > 2 * s) {
			cout << n - 1;
			break;
		}
		n++;
	}
	return 0;
}