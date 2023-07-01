#include<iostream>
#include<cmath>

using namespace std;

long long int n, r, c;
long long int res;

void divide(long long int sx, long long int ex, long long int sy, int ey) {
	long long int midx = (sx + ex) / 2;
	long long int midy = (sy + ey) / 2;
	if (r == midx && c == midy) {
		res += ((midx - sx + 1) * (midy - sy + 1) - 1);
	}
	else if (r <= midx && c <= midy) { // 1
		divide(sx, midx, sy, midy);
	}
	else if (r <= midx && c > midy) { // 2
		res += ((midx - sx + 1) * (midy - sy + 1));
		divide(sx, midx, midy + 1, ey);
	}
	else if (r > midx && c <= midy) { // 3
		res += ((midx - sx + 1) * (ey - sy + 1));
		divide(midx + 1, ex, sy, midy);
	}
	else if (r > midx && c > midy) { // 4
		res += ((midx - sx + 1) * (ey - sy + 1) + (ex - midx) * (midy - sy + 1));
		divide(midx + 1, ex, midy + 1, ey);
	}
}
int main() {
	cin >> n >> r >> c;
	divide(0, pow(2, n) - 1, 0, pow(2, n) - 1);
	cout << res;
	return 0;
}