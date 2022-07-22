#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;

	vector<ll> prefix(n,0), suffix(n,0);
	for (int i = 0; i < n-1; i++)
		prefix[i+1] = prefix[i] + max(a[i] - a[i+1], 0);
	for (int i = n-2; ~i; i--)
		suffix[i] = suffix[i+1] + max(a[i+1] - a[i], 0);

	for (int i = 0; i < m; i++) {
		ll s, t; cin >> s >> t; s--; t--;
		ll out = t > s ? prefix[t] - prefix[s] : suffix[t] - suffix[s];
		cout << out << "\n";
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

