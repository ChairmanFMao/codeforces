#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	string a[2];
	cin >> a[0] >> a[1];;

	sort(all(a[0]));
	sort(all(a[1]));

	string c = "";
	int current = 0, aptr = 0, bptr = 0, last = 0;
	while (aptr < n && bptr < m) {
		if (current >= k) {
			current = 1;
			c += a[last == 1 ? 0 : 1][last == 1 ? aptr : bptr];
			if (last == 1)
				aptr++;
			else
				bptr++;
			last = 3 - last;
			continue;
		}

		if (a[0][aptr] == a[1][bptr]) {
			if (n-aptr < m-bptr) {
				c += a[0][aptr];
				aptr++;
				current = last == 2 ? current+1 : 1;
				last = 2;
			} else {
				c += a[1][bptr];
				bptr++;
				current = last == 1 ? current+1 : 1;
				last = 1;
			}
		} else if (a[0][aptr] > a[1][bptr]) {
			c += a[1][bptr];
			bptr++;
			current = last == 1 ? current+1 : 1;
			last = 1;
		} else {
			c += a[0][aptr];
			aptr++;
			current = last == 2 ? current+1 : 1;
			last = 2;
		}

	}
	
	cout << c << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
		solve();
}

