#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// We don't want to try to simulate this as mxN = 1e9
// Can just keep reducing everything by k
// colours can repeat every k
// I think there are some edge cases when n%k != 0

void solve() {
	ll n, m, k;
	cin >> n >> m >> k;
	vector<ll> a(m);
	for (ll& i : a)
		cin >> i;

	sort(all(a));
	reverse(all(a));
	ll extra = n%k;
	for (ll i = 0; i < m; i++) {
		if (n/k < a[i]) {
			if (n/k + 1 >= a[i] && extra > 0) {
				extra--;
				continue;
			}
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
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

