#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Longest simple cycle
// Just need the connections to not lead to the same node
// c is the lengths of the chains
// a is the previous node the top is connected to
// b is the previous node tha the bottom is connected to
// definitely dp
// Can start from any point, need to find best end
//
// Copied implementation from tutorial
// I struggled with moving between the dp states

void solve() {
	int n;
	cin >> n;
	vector<ll> a(n), b(n), c(n);
	for (ll& i : c)
		cin >> i;
	for (ll& i : a)
		cin >> i;
	for (ll& i : b)
		cin >> i;

	vector<ll> dp(n,0);
	for (int i = 1; i < n; i++) {
		// Ending here
		dp[i] = c[i] + 1 + abs(a[i]-b[i]);
		// Continuing, if it is possible (a[i] != b[i])
		if (a[i] - b[i])
			dp[i] = max(dp[i], c[i] + 1 + dp[i-1] - abs(a[i]-b[i]));
	}

	cout << *max_element(all(dp)) << "\n";
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

