#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// If it is an odd number just do loads of the same
// if it is an even number add a big number at the end?

void solve() {
	ll n;
	cin >> n;

	if (n&1) {
		for (ll i = 0; i < n; i++)
			cout << "1 ";
		cout << "\n";
		return;
	}

	cout << "1 3 ";
	for (ll i = 0; i < (n/2)-1; i++)
		cout << "2 2 ";
	cout << "\n";
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

