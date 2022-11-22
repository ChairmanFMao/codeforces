#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Just encroach from the sides with two pointer approach
// unsure why this approach is not working
// might be easier to do the binary search approach

void solve() {
	ll n, q;
	cin >> n >> q;
	vector<ll> a(n);
	for (ll& i : a)
		cin >> i;

	vector<ll> pres(n+1,0), prex(n+1,0);
	for (ll i = 1; i <= n; i++) {
		pres[i] = pres[i-1] + a[i-1];
		prex[i] = (prex[i-1] ^ a[i-1]);
	}

	ll l, r;
	cin >> l >> r;
	ll outl = l, outr = r;
	ll out = pres[outr]-pres[outl-1] - (prex[outr]^prex[outl-1]);
	
	ll current = 1;
	while (outl < outr) {
		if ((pres[outr]-pres[outl] - (prex[outr]^prex[outl])) >= out) {
			out = (pres[outr]-pres[outl] - (prex[outr]^prex[outl]));
			outl++;
			current = 1;
		} else
			break;
	}
	while (outl < outr) {
		if ((pres[outr-1]-pres[outl-1] - (prex[outr-1]^prex[outl-1])) >= out) {
			out = (pres[outr-1]-pres[outl-1] - (prex[outr-1]^prex[outl-1]));
			outr--;
			current = 1;
		} else
			break;
	}

	cout << outl << " " << outr << "\n";
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

