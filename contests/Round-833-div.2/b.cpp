#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// each character occurs does not exceed distinct
// just like some dp thing?
// just use like prefix sums to do this
// an O(n^2) solution will not work
// we are trying to find number of diverse ones
// just use like a sliding window?
// might be possible with a binary search?
// actually I don't think so as its not monotonic
// only continuous substrings
// might be easier just to find not diverse ones
// we just don't need to consider ones of length more than 101
// wrong answer on pretest 2 somehow
// I thought the error was about a < rather than <= but it is not
// any string of length 101 or greater will not be diverse
// now I get tle
// now I get wa on test 2
// I got it get past test case 2 but now I get wa on test case 3

void solve() {
	ll n;
	string s;
	cin >> n >> s;
	vector<ll> a(sz(s),0);
	for (ll i = 0; i < n; i++)
		a[i] = s[i]-48;
	
	ll out = 0;
	for (ll i = 0; i < n; i++) {
		set<ll> s;
		vector<ll> occurs(10,0);
		for (ll j = 0; j <= 101; j++) {
			if (i+j >= n)
				break;
			s.insert(a[i+j]);
			occurs[a[i+j]]++;
			if (sz(s) >= *max_element(all(occurs)))
				out++;
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

