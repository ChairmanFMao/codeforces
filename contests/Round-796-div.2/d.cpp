#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// Must finish at end point
// There would be a triangle number trailing behind
// This must be subtracted from the total
// The total would be the number of mushrooms grown during the time
// period minus the trailing triangle

void solve() {
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	for (ll& i : a)
		cin >> i;
	vector<ll> window(n+1,0);
	for (ll i = 0; i < n; i++)
		window[i+1] = a[i] + window[i];

	ll best = 0;
	if (k < n) {
		for (int i = 0; i <= n-k; i++)
			best = max(best,window[i+k]-window[i]);
		cout << best + (k*(k-1))/2 << "\n";
		return;
	}

	ll current = window[n];

	if (n == 1) {
		cout << current + k-1 << "\n";
		return;
	}

	current += n*k;
	current -= (n*(n+1))/2;

	cout << current << "\n";
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

