#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Minimum number of extra floors needed
// We can choose the ending cool ones on the even numbers
// This would just a be a little casework
// Still wrong answer on pretest 2 some how
// I think there are some more edge cases with even numbers
// Potentially something to do with dp
const int mxN = 1e5;
int n;
vector<ll> h(mxN), cost(mxN);

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> h[i];

	for (int i = 1; i < n-1; i++)
		cost[i] = max(max(h[i-1],h[i+1])+1-h[i],0ll);

	if (n&1) {
		ll out = 0;
		for (int i = 1; i < n-1; i+=2)
			out += cost[i];
		cout << out << "\n";
		return;
	}

	vector<vector<ll> > dp(n, vector<ll>(2));
	for (int i = 1; i < n-1; i++) {
		int t = i-2<0?0:i-2, th = i-3<0?0:i-3;
		dp[i][0] = dp[t][0] + cost[i];
		dp[i][1] = min(dp[t][1], dp[th][0]) + cost[i];
	}

	cout << min(dp[n-2][1],dp[n-3][0]) << "\n";
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

