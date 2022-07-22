#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// I looked at tutorial to solve before contest for peace of mind
// It has a very nice maths solution
const int MOD = 1e9+7;

void solve() {
	ll n, k;
	cin >> n >> k;

	ll out = 1;
	for (int i = 0; i < k; i++)
		out = (out * n) % MOD;
	
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

