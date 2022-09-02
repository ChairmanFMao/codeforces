#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

void solve() {
	ll n, k;
	cin >> n >> k;
	vector<ll> a(k);
	for (ll& i : a)
		cin >> i;

	ll best = 0, type = 0;
	for (int i = 0; i < k; i++) {
		ll current = n/a[i] * a[i];
		if (current > best) {
			best = current;
			type = i;
		}
	}

	cout << type+1 << " " << n/a[type] << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

