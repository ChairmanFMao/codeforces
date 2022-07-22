#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Use cells of all size 1

void solve() {
	ll x;
	cin >> x;

	ll out = 0;
	for (ll i = 1; x >= 0;) {
		x -= (i*(i+1))/2;
		i += i+1;
		out++;
	}

	out--;

	cout << out << "\n";
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

