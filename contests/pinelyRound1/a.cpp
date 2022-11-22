#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// wa on pretest 2
// might just try to generate them?

void solve() {
	ll n, a, b;
	cin >> n >> a >> b;

	if (n-a-b >= 2 || n-a-b == -n)
		cout << "YES\n";
	else
		cout << "NO\n";
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

