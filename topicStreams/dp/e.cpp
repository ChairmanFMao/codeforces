#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// There are more keys than people
// Maybe dp over n
// You don't want any of the paths to cross for optimal solution
// You just match the last person to a key,
// All of the other people must just fall into place after
// Somehow getting wa on test 8 - due to < rather than <=
// Watched Galen Colin video for those observations

void solve() {
	ll n, k, p;
	cin >> n >> k >> p;
	vector<ll> a(n), b(k);
	for (ll& i : a)
		cin >> i;
	for (ll& i : b)
		cin >> i;

	sort(all(a));
	sort(all(b));

	ll out = 1e16;
	for (int i = 0; i <= k-n; i++) {
		ll current = 0;
		for (int j = i; j < i+n; j++)
			current = max(current,llabs(a[j-i]-b[j])+llabs(p-b[j]));

		out = min(current,out);
	}

	cout << out << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

