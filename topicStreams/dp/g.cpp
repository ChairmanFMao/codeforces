#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// I did this without help, this was a very cool dp problem!
// I liked it a lot!

// I think that this can be done with just maths, idk tho
const int mxT = 1e2, mxV = 1100;
// First dimension is for the turn
// Second dimension is for the velocity
// The value is the distance travelled
int dp[mxT+1][mxV+1];

void solve() {
	memset(dp, 0, sizeof dp);

	int v1, v2, t, d;
	cin >> v1 >> v2 >> t >> d;

	dp[0][v1] = v1;
	for (int i = 1; i < t; i++) {
		for (int j = 0; j <= mxV; j++) {
			if (!dp[i-1][j])
				continue;
			for (int k = -d; k <= d; k++) {
				// This is just to prevent index errors
				if (j + k < 0)
					continue;
				dp[i][j+k] = max(dp[i][j+k], dp[i-1][j] + (i>1?j:0));
			}
		}
	}

	int out = 0;
	for (int i = 0; i < mxV; i++)
		out = max(out, dp[t-1][v2]);
	
	cout << out+v2 << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

