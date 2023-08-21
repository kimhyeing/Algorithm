#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int alpha[26];
string arr[10];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		string word = arr[i];
		for (int j = 0; j < word.size(); j++) {
			alpha[word[j] - 'A'] += (pow(10, word.size() - j - 1));
		}
	}

	sort(alpha, alpha + 26);
	int sum = 0;
	for (int i = 25; i > 0; i--) {
		sum += ((i-16) * alpha[i]);
	}
	cout << sum;
	return 0;
}