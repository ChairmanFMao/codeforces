#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// got a wa because I was missing one comparison

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n), t(n);
	for (int& i : a)
		cin >> i;
	for (int& i : t)
		cin >> i;
	
	ll out = 0;
	for (int i = 0; i < n; i++)
		if (t[i])
			out += a[i];

	ll current = 0;
	for (int i = 0; i < k; i++)
		if (!t[i])
			current += a[i];
	
	vector<int> dp(n-k+1);
	for (int i = 0; i <= n-k; i++) {
		dp[i] = current;
		if (!t[i])
			current -= a[i];
		if (!t[i+k])
			current += a[i+k];
	}

	cout << out + *max_element(all(dp)) << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

