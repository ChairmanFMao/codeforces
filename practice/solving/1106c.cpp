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
	for (ll&i : a)
		cin >> i;

	sort(all(a));
	ll out = 0;
	for (int i = 0; i < n/2; i++)
		out += (a[i] + a[n-1-i]) * (a[i] + a[n-1-i]);

	cout << out << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

