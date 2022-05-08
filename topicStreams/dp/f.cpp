#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// Watched galen colin video for ideas and most of code
// derangments - lookup and understand

ll choose(ll n, ll k) {
	ll top = 1;
	for (int i = n-k+1; i <= n; i++)
		top *= i;
	
	for (int i = 1; i <= k; i++)
		top /= i;

	return top;
}

void solve() {
	ll n, k;
	cin >> n >> k;
	
	ll out = 1;
	if (k >= 2)
		out += choose(n,2);
	if (k >= 3)
		out += 2 * choose(n,3);
	if (k >= 4)
		out += 9 * choose(n,4);

	cout << out << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

