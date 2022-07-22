#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

ll factorial(ll n) {
	ll out = 1;
	for (ll i = 2; i <= n; i++)
		out *= i;
	return out;
}

ll choose(ll n, ll k) {
	ll top = factorial(n);
	top /= factorial(k);
	top /= factorial(n-k);
	return top;
}

void solve() {
	string a, b;
	cin >> a >> b;
	
	int want = 0, current = 0, q = 0;
	for (char c : a)
		want += c == '+' ? 1 : -1;
	for (char c : b) {
		current += c == '+' ? 1 : c == '-' ? -1 : 0;
		q += (int) (c == '?');
	}

	// We need to find out how many + we need in the output
	if (q < abs(want-current)) {
		cout << "0\n";
		return;
	}

	ll wanted = abs(want-current);
	if (wanted < q) {
		wanted += (q-wanted)/2;
	}


	long double div = 1<<q;
	cout << choose(q, wanted) / div << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.precision(10);
	
	solve();
}

