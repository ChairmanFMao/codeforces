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
	vector<ll> s(n), f(n);
	for (ll& i : s)
		cin >> i;
	for (ll& i : f)
		cin >> i;

	ll time = 0;
	for (int i = 0; i < n; i++) {
		time = max(s[i],time);
		cout << f[i]-time << " \n"[i==n-1];
		time = f[i];
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
		solve();
}

