#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// You can add or subtract the element from a[i]
// What if we just tested using all of the a[i] as the zero
// then we took the min, got a wa on pretest 4 somehow
// Unsure where the error would be - it was with integer overflow

const ll mxN = 5e3;
vector<ll> a(mxN);
ll n;

ll solve2(ll zero) {
	ll out = 0;
	vector<ll> b(n, 0);
	b[zero] = 0;
	for (ll i = zero-1; i >= 0; i--) {
		b[i] = ((b[i+1] / a[i]) * a[i]) - a[i];
		out += -(b[i+1] / a[i]) + 1;
	}

	for (ll i = zero+1; i < n; i++) {
		b[i] = ((b[i-1] / a[i]) * a[i]) + a[i];
		out += (b[i-1] / a[i]) + 1;
	}
	
	return out;
}

void solve() {
	cin >> n;
	for (ll i = 0; i < n; i++)
		cin >> a[i];

	ll out = 1e18;
	for (ll i = 0; i < n; i++)
		out = min(out, solve2(i));

	cout << out << "\n";
	
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cout << "\n";
	solve();
}

