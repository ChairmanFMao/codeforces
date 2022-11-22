#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Need to find a constant time way to generate it
// its not every other number
// there are 3 between every square?
// wa on pretest 2, I think there is some edge case thing
// wa on pretest 4 now, unsure of the new edge case
// wa on pretest 4 again somehow
// why, more wa somehow
// Current code doesn't work for last case
// why!!!!!!!
// this problem is not very enjoyable ;-;

void solve() {
	// Why should these need to be long double?
	// This is so stupid
	long double l, r;
	cin >> l >> r;
	
	ll rf = (ll)floor(sqrt(r)), lf = (ll)floor(sqrt(l));
	ll out = (rf-lf)*3ll;

	ll rc = rf*rf;
	while (rc <= r) {
		out++;
		rc += rf;
	}
	ll lc = lf*lf;
	while (lc < l) {
		out--;
		lc += lf;
	}

	cout << out << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	random_device dev;
	mt19937 rng(dev());
	ll cap = 1e5;
	uniform_int_distribution<mt19937::result_type> dist(1,cap);
	cout << "\n";
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
		solve();
}

