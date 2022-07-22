#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// something with modulo

void solve() {
	ll n, g, b;
	cin >> n >> g >> b;

	ll rg = ((n+1)/2-1)/g;
	ll total = rg * (g+b), good = rg * g;

	if (total < n) {
		good += (n-total)/(g+b) * g;
		total += (n-total)/(g+b);
	}

	if (good < (n+1)/2) {
		total += (n+1)/2 - good;
	}

	if (total < n) {
		total += n - total;
	}

	cout << total << "\n";
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

