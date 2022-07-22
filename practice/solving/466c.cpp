#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

void solve() {
	ll n;
	cin >> n;
	vector<ll> a(n);
	for (ll& i : a)
		cin >> i;

	ll total = 0;
	for (ll i : a)
		total += i;
	
	if (total%3) {
		cout << "0\n";
		return;
	}
	ll third = total/3, out = 0;
	ll first = 0;
	total = 0;
	for (int i = 0; i < n; i++) {
		total += a[i];
		if (total == third)
			first++;
		if (total == third+third)
			out += first;
	}

	if (!third) {
		first -= 2;
		out = (first*(first+1))/2;
	}

	cout << out << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

