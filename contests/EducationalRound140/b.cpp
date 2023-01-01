#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Only possible if a[i] > a[j], from i to j
// just sort and greedy maybe

void solve() {
	ll n, val;
	cin >> n >> val;
	vector<ll> a(n-1);
	for (ll& i : a)
		cin >> i;

	sort(all(a));
	for (ll i = 0; i < sz(a); i++)
		val = max(val,(val+a[i]+1)/2);

	cout << val << "\n";
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

