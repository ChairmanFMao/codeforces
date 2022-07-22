#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// Edge cases moment

void solve() {
	ll n;
	cin >> n;
	if (n&1 || n == 2)
		cout << "-1\n";
	else {
		cout << n/6 + (n%6?1:0) << " " << n/4 << "\n";
	}
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

