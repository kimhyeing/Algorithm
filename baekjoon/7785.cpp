#include<iostream>
#include<set>
#include<string>

using namespace std;

int main() {
	set<string, greater<string>>s;
	int n;
	string str1, str2;
	cin >> n;
	while(n--) {
		cin >> str1 >> str2;
		if (str2 == "enter") {
			s.insert(str1);
		}
		else {
			s.erase(str1);
		}
	}

	for (auto iter : s) {
		cout << iter << "\n";
	}
	return 0;
}