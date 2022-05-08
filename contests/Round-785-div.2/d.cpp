#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// You can't generate A and B as the contraints are too high
// Difference of A must be a factor of the difference of C
// Can correctly identify the 0 and -1 outputs
// Just need to make all of the A subsequences
// 1 <= t <= 100, so algorithm doesn't have to be that fast
// Looked at tutorial after, I was kinda close in the contest
// Got a wa because testing for 0 and -1 wasn't through enough
// After this got accepted

const int MOD = 1e9+7;

ll lcm(ll f, ll s) {
	return (f*s) / __gcd(f,s);
}

void solve() {
	ll b, q, y;
	cin >> b >> q >> y;
	ll c, r, z;
	cin >> c >> r >> z;

	if (c < b || c > b+q*(y-1) || c+r*(z-1) < b || b+q*(y-1) < c+r*(z-1) || (c-b)%q || (c+r-b)%q) {
		cout << "0\n";
		return;
	}

	// This is the cap for the last term of A: c+r*(z+1)
	// This is the cap for the first term of A: c-r
	if (c-r < b || b+(q*y-1) < c+r*z) {
		cout << "-1\n";
		return;
	}

	ll out = 0;
	for (ll i = 1; i*i <= r; i++) {
		if (!(r%i)) {
			// The lcm calls verify that there won't be any colliding
			// terms that aren't in sequence C
			if (lcm(i,q) == r)
				out = (out + (r/i)*(r/i)) % MOD;
			// Just does the same thing with r/i instead of i
			// We need to make sure that its not the root of r because
			// then we would be double counting it
			if (i*i != r && lcm(r/i,q) == r)
				out = (out + i*i) % MOD;
		}
	}
	
	cout << out << "\n";
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

