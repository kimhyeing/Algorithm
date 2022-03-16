#include<iostream>
#include<algorithm>

using namespace std;

long long int a, b;
int result = 100000;

void dfs(long long int x, int count) {
	if (x == b) {
		result = min(result, count);
	}
	else if (x > b)
		return;
	dfs(2 * x, count + 1);
	dfs((10 * x + 1), count + 1);
}
int main() {
	cin >> a >> b;
	dfs(a, 1);
	if (result == 100000) cout << -1;
	else cout << result;
	return 0;
}