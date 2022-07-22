#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// The two operations are bitwise shift upwards and downwards
// Bits at the end of the number can be erased
// Unsure how to do this in better than O(n^2)
// More difficult to get numbers with more bits set
// bits set can only be reduced, not increased
// Watched some of the newton school tutorial video
// Also looked at the editorial
// We need to get all the numbers in a to be odd
// We can then perform shifts downwards on numbers in b until they match
// if b == 1 and they don't match then the sets can never match

class Comp {
	public:
		bool operator() (ll a, ll b) {
			return a < b;
		}
};

void solve() {
	ll n;
	cin >> n;
	vector<ll> a(n), b(n);
	for (ll& i : a)
		cin >> i;
	for (ll& i : b)
		cin >> i;

	for (int i = 0; i < n; i++)
		while (!(a[i] % 2))
			a[i] >>= 1;

	map<ll,ll> m;
	for (ll i : a)
		m[i]++;

	priority_queue<ll, vector<ll>, Comp> q;
	for (ll i : b)
		q.push(i);

	ll total = n;
	while (total) {
		ll current = q.top();
		q.pop();
		if (m[current]) {
			m[current]--;
			total--;
		} else if (current == 1) {
			cout << "NO\n";
			return;
		} else
			q.push(current >> 1);
	}

	cout << "YES\n";
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

