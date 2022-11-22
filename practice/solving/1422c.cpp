#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

const ll MOD = 1e9+7;
// Unsure on how to store the numbers
// There are (log(base 10)n)^2 different subsequences
// I think that this is a dp problem
// store the number with mod dp over that? potentially 1e9 combos
// need to remove original one
// not necessarily unique
// need the bits on the other side as well
// have a map for all of the ones that have ended?
// Looked at editorial
// digit dp is very nice
// Just need to build up right side with dp, and calculate the
// left side on the fly every time

void solve() {
	string s;
	cin >> s;

	reverse(all(s));

	ll out = 0, current = 0, power = 1, n = sz(s);
	for (int i = 0; i < n; i++) {
		// Does all of the ones to the right
		out = (out + (s[i]-48) * current % MOD) % MOD;
		// Does all of the ones to the left
		out = (out + (s[i]-48) * ((n-i)*(n-i-1))/2 % MOD * power % MOD) % MOD;

		// Keeps progressively building up current
		current = (current + (i+1)*power % MOD) % MOD;
		// Keeps progressively building up power
		power = (power * 10) % MOD;
	}

	cout << out << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

