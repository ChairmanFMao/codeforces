#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Need to avoid O(nm) complexity
// Just exit early if the gcd gets to 1?
// Doesn't work well if there aren't many that reach 1
// brute force gets tle on test 8
// looked at tags and its just maths and number theory
// There must be something mathematical that I'm missing
// something storing with modulus maybe?
// Ended up looking at solutions
// need to use properties of the gcd function
// gcd(a,b) == gcd(a,b-a)
// Just a mathematical observation basically
// it allows u to do precalculations and get O(n log n)

void solve() {
	ll n, m;
	cin >> n >> m;
	vector<ll> a(n), b(m);
	for (ll& i : a)
		cin >> i;
	for (ll& i : b)
		cin >> i;

	sort(all(a));
	ll current = 0;
	for (ll i = 1; i < n; i++)
		current = __gcd(current,a[i]-a[0]);

	for (ll i = 0; i < m; i++)
		cout << __gcd(current,a[0]+b[i]) << " ";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

