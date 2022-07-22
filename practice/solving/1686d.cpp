#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// I watched a video on this, very interesting problem
// I had the right idea in the contest but didn't implement it right

void solve() {
	int a, b, c, d;
	string s;
	cin >> a >> b >> c >> d >> s;

	int totala = a + c + d, totalb = b + c + d, ca = 0, cb = 0;
	for (char c : s) {
		if (c == 'A')
			ca++;
		else
			cb++;
	}

	if (totala != ca || totalb != cb) {
		cout << "NO\n";
		return;
	}

	int extra = 0;
	vector<int> ab, ba;

	int start = 0, n = sz(s);
	for (int i = 0; i < n; i++) {
		if (i == n-1 || s[i] == s[i+1]) {
			if ((i-start+1) & 1) {
				extra += (i-start+1)/2;
			} else {
				if (s[start] == 'A')
					ab.push_back(i-start+1);
				else
					ba.push_back(i-start+1);
			}
			start = i+1;
		}
	}

	sort(all(ab));
	sort(all(ba));

	int abCount = 0, baCount = 0;
	for (int i = 0; i < sz(ab); i++) {
		if (ab[i]/2 + abCount <= c)
			abCount += ab[i]/2;
		else {
			baCount += (ab[i] - ((c - abCount)<<1)-2)/2;
			abCount = c;
		}
	}

	if (abCount < c) {
		int extra2 = min(extra, c - abCount);
		extra -= extra2;
		abCount += extra2;
	}

	for (int i = 0; i < sz(ba); i++) {
		if (ba[i] == 2)
			baCount++;
		else if (baCount < d) {
			if (baCount + ba[i]/2 <= d)
				baCount += ba[i]/2;
			else {
				abCount += (ba[i] - ((d - baCount)<<1)-2)/2;
				baCount = d;
			}
		} else
			abCount += (ba[i]-2)/2;
	}

	if (extra)
		baCount += extra;

	baCount = min(baCount, d);
	abCount = min(abCount, c);
	cout << (baCount == d && abCount == c ? "YES" : "NO") << "\n";
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

