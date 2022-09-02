#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

void solve() {
	ll n, q;
	cin >> n >> q;
	vector<ll> p(n);
	for (ll& i : p)
		cin >> i;

	sort(all(p),greater<ll>());
	vector<ll> prefix(n+1,0);
	for (int i = 0; i < n; i++)
		prefix[i+1] = prefix[i] + p[i];

	for (int i = 0; i < q; i++) {
		ll y, x; cin >> y >> x;
		cout << prefix[y] - prefix[y-x] << "\n";
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

