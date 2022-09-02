#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// number of elements to remove
// k/6 subsequences?
// subsequences here are just increasing?
// Two longest increasing subsequences?
// didn't notice the constraint on the values of a
// looked at editorial, not that bad

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	map<int,int> m = {{4,0},{8,1},{15,2},{16,3},{23,4},{42,5}};
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] = m[a[i]];
	}
	

	vector<int> dp(6,0);
	for (int i = 0; i < n; i++) {
		if (!a[i])
			dp[0]++;
		else if (dp[a[i]-1]) {
			dp[a[i]]++;
			dp[a[i]-1]--;
		}
	}

	// length of array minus the 6 streaks present
	cout << n - dp[5]*6 << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

