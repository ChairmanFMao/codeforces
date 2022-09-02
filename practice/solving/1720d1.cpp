#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// The array a is zero indexed
// The b array is in ascending order
// just greedily look for next bit
// dp over length and last bit value?
// ended up looking at tutorial relatively quickly
// pull dp and only need to store the last 512 due to contraints
// the dp is actually really easy, just needed to make the
// observation to allow the code to work

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;

	vector<ll> dp(n+1,1);
	for (int i = 0; i < n; i++)
		for (int j = i-1; j >= max(i-512,0); j--)
			if ((a[j] ^ i) < (a[i] ^ j))
				dp[i] = max(dp[i], dp[j]+1);

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

