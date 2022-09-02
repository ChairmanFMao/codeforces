#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Somehow need to deal with queries quickly
// I ended up reading the tutorial because I didn't solve this in contest
// I think that I had the idea but didn't think of the implementation

void solve() {
	ll n, m;
	cin >> n >> m;
	vector<int> a(n+2,0);
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	ll current = 0;
	for (int i = 1; i <= n; i++)
		if (a[i] != a[i+1])
			current += i * (n-i);

	for (int q = 0; q < m; q++) {
		int b, c; cin >> b >> c;
		// Reduces current before change
		if (b > 0 && a[b] != a[b-1])
			current -= (b-1) * (n-(b-1));
		if (a[b] != a[b+1])
			current -= b * (n-b);
		// Does the change
		a[b] = c;
		// Increases current after the change
		if (b > 0 && a[b] != a[b-1])
			current += (b-1) * (n-(b-1));
		if (a[b] != a[b+1])
			current += b * (n-b);
		
		// We add that as that is the number of segments in the first place
		// current only deals with the extras due to changes
		cout << current + (n*(n+1))/2 << "\n";
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

