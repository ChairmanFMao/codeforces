#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// they want to swap to a 0 to win
// therefor, they want to swap a 1 in to secure the win
// whoever reaches all 2 first loses
// whoever gets a 1 first wins
// when array gets to all equal, that player loses

void solve() {
	int n;
	cin >> n;
	vector<ll> a(n);
	for (ll& i : a)
		cin >> i;

	cout << (a[0] != 1 ? "Alice" : "Bob") << "\n";
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

