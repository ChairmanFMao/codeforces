#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

void solve() {
	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	for (string& i : s)
		cin >> i;
	vector<ll> a(m);
	for (ll& i : a)
		cin >> i;
	
	ll out = 0;
	for (int i = 0; i < m; i++) {
		vector<ll> occurs(5,0);
		for (string j : s)
			occurs[j[i]-65]++;
		out += a[i] * (*max_element(all(occurs)));
	}

	cout << out << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

