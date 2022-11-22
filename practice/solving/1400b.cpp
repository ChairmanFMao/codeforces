#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

ll solve2(ll p, ll f, ll sn, ll wn, ll s, ll w, ll i) {
	ll out = i;
	p -= i*s;
	sn -= i;

	ll a = min(p/w,wn);
	wn -= a;
	p -= a * w;
	out += a;

	ll b = min(f/s,sn);
	sn -= b;
	f -= b * s;
	out += b;

	ll c = min(f/w,wn);
	wn -= c;
	f -= c * w;
	out += c;

	return out;
}

void solve() {
	ll p, f, sn, wn, s, w;
	cin >> p >> f >> sn >> wn >> s >> w;

	if (p < f)
		swap(p,f);
	if (s > w) {
		swap(s,w);
		swap(sn,wn);
	}

	ll out = 0;
	for (ll i = 0; i <= sn; i++) {
		if (p - s*i < 0)
			continue;
		out = max(out,solve2(p,f,sn,wn,s,w,i));
	}

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

