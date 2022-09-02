#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

void solve() {
	ll a, b, c, d;
	cin >> a >> b >> c >> d;

	ll f = __gcd(b,d), s = (b*d)/f;
	a *= s/b;
	c *= s/d;

	ll out = 0;
	if (a == c)
		out = 0;
	else if (min(a,c) == 0)
		out = 1;
	else if (max(a,c)%min(a,c) == 0)
		out = 1;
	else
		out = 2;

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

