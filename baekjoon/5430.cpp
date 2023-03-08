#include<iostream>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t, n, x;
	string p, arr, element;
	cin >> t;
	while (t--) {
		vector<int>dq;
		
		bool front = true;
		bool error = false;
		
		cin >> p >> n >> arr;

		if (n > 0) {
			arr = arr.substr(1, arr.size() - 1);
			istringstream ss(arr);
			while (getline(ss, element, ',')) {
				dq.push_back(stoi(element));
			}
		}

		int f = 0;
		int b = dq.size() - 1;

		for (int i = 0; i < p.size(); i++) {
			if (p[i] == 'R') {
				front = !front;
			}
			else {
				if (f > b) {
					error = true;
					break;
				}
				else if (front) f++;
				else b--;
			}
		}

		if (!error) {
			cout << "[";
			while (f <= b) {
				x = front ? dq[f] : dq[b];

				cout << x;
				if (f != b)cout << ",";
				front ? f++ : b--;
			}
			cout << "]\n";
		}
		else cout << "error\n";
	}
	return 0;
}