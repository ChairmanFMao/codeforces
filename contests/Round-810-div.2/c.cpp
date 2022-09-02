#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// WA on pretest 2
// I think there are edge cases with odd numbers
// WA on pretest 7 now, I think that there is just one more
// edge case that I need to get

void solve() {
	ll n, m, k;
	cin >> n >> m >> k;
	vector<ll> a(k);
	for (ll& i : a)
		cin >> i;

	ll out = 0, outf = 0, out2 = 0, out2f = 0;
	for (int i = 0; i < k; i++) {
		if (a[i]/m >= 2) {
			out += a[i]/m;
			if (a[i]/m >= 3)
				outf = 1;
		} if (a[i]/n >= 2) {
			out2 += a[i]/n;
			if (a[i]/n >= 3)
				out2f = 1;
		}
	}

	if (n & 1) {
		if (outf && out >= n) {
			cout << "YES\n";
			return;
		}
	} else {
		if (out >= n) {
			cout << "YES\n";
			return;
		}
	}

	if (m & 1) {
		if (out2f && out2 >= m) {
			cout << "YES\n";
			return;
		}
	} else {
		if (out2 >= m) {
			cout << "YES\n";
			return;
		}
	}

	cout << "NO\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cout << "\n";
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
		solve();
}

