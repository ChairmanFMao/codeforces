#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

void solve() {
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;

	cout << max(min(a,d) * e + min(b,min(c,d-min(a,d))) * f, min(b,min(c,d)) * f + min(a,d-min(b,min(c,d))) * e) << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

