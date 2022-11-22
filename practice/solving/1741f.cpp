#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Need to output the distance to nearest different coloured
// segment for every segment
// something to do with a binary search I think
// just do it for closest left end and closest right end
// have two lists and sort one by left end
// then sort the other by right end
// just get one with right in or closest to range
// then get other with left in or closest to range
// then take the min between these two values

struct Segment {
	ll l, r, c;
};

void solve() {
	ll n;
	cin >> n;
	vector<Segment> segments(n);
	for (Segment& i : segments)
		cin >> i.l >> i.r >> i.c;

	
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

