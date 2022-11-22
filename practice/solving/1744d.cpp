#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

void solve() {
	int n;
	cin >> n;
	vector<ll> a(n);
	for (ll& i : a)
		cin >> i;

	ll two = 0;
	vector<ll> extra;
	for (ll i = 0; i < n; i++) {
		while (a[i] % 2 == 0 && a[i]) {
			a[i] >>= 1;
			two++;
		}
		ll current = i+1, val = 0;
		while (current % 2 == 0 && current) {
			current >>= 1;
			val++;
		}
		extra.push_back(val);
	}

	sort(all(extra));
	reverse(all(extra));
	ll ops = 0, ptr = 0;
	while (ptr < n && two < n) {
		two += extra[ptr];
		ptr++;
		ops++;
	}

	cout << (two < n ? -1 : ops) << "\n";
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

