#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Every customer has to get more packs than they wanted
// For every value in between we want the mod to be great than or equal to the number
// should choose r+1 to be a

void solve() {
	int l, r;
	cin >> l >> r;
	cout << (r-l+1 <= (r+1)/2 ? "YES" : "NO") << "\n";
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

