#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// You need to generate a from c
// The first number tells you where the first zero is
// need to cater for the ending parts
// Its constructive, unsure what to do
// Currently I am just checking if each number is greater than its index

void solve() {
	ll n;
	cin >> n;
	vector<ll> a(n,-1), b(n), c(n);
	for (ll& i : c)
		cin >> i;

	ll total = 0;
	for (ll i : c)
		total += i;
	total /= n;
	
	for (int i = n-1; ~i; i--) {
		b[i] = min(total,n-i);
	}

	for (int i = 0; i < n; i++) {
		a[i] = c[i] > b[i];
	}

	for (int i : a)
		cout << i << " ";
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

