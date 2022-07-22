#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

void solve() {
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int l, r; cin >> l >> r;

		// l needs to be odd and r needs to be even

		int out = 0;
		if (!(l&1)) {
			out += l;
			l++;
		}
		if (r&1) {
			out -= r;
			r--;
		}

		out += (r-l+1)/2;

		cout << out << "\n";
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

