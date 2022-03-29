#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Even with caching it times out on test 42
// I used a bit more clever stuff storing the minimum
// Not sure that I did it how it was intended
// After looking at solution decided to rewrite the code
// This is much better as I was previously using a recursive function
// along with caching it was faster, basically I was attempting to implement
// dp with recursion.

const int mxN = 1e5;
ll dp[mxN+1], n;
map<ll,ll> points;

void solve() {
	cin >> n;
	for (int i = 0, a; i < n; i++) {
		cin >> a;
		points[a] += a;
	}
	
	memset(dp, 0, sizeof dp);
	dp[1] = points[1];
	for (int i = 2; i < mxN+1; i++)
		dp[i] = max(dp[i-1], dp[i-2]+points[i]);

	cout << dp[mxN] << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}
