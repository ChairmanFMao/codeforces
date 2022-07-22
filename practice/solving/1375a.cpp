#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Looked at tutorial ;-;
// For all odd indexes it will be negative and for all even it will be
// positive, zero is excluded

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		cout << (i & 1 ? -abs(a) : abs(a)) << " ";
	}
	cout << "\n";
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

