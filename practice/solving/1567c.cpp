#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// number of ways, feels like dp honestly
// can't dp nicely, there is a spot in the middle
// honestly I think that brute force might work due to the nature
// of the problem with such small constraints
// looked at solution, trying to do the dp
// its kinda like what I was thinking of

// First dimension for which digit
// Second dimension is for current carry
// Third dimension is for next carry
// Value is how many ways to get there
int dp[11][2][2];

void solve() {
	int n;
	cin >> n;
	string s = to_string(n);
	reverse(all(s));
	int length = sz(s);
	memset(dp, 0, sizeof dp);

	dp[0][0][0] = 1;
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				for (int l = 0; l < 2; l++) {
					for (int m = 0; m < 2; m++) {
						if ((j+k+l)%10 == s[i]-48)
							dp[i+1][m][(j+k+l)/10] += dp[i][l][m];
					}
				}
			}
		}
	}
	
	// there are 2 invalid ones of n and 0 and 0 and n
	// so we need to take away 2
	cout << dp[length][0][0]-2 << "\n";
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

