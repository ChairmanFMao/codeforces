#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Find all the winning integers
// 2**18 is brute forceable in linear time ig
// 2**18 * 20 is also possible and I think its more viable
// remove some of each team with the number of 0 and 1

void solve() {
	ll n;
	string s;
	cin >> n >> s;
	ll one = 0, zero = 0;
	for (char c : s) {
		if (c&1)
			one++;
		else
			zero++;
	}

	for (ll i = (1<<one); i <= (1<<n)+1-(1<<zero); i++)
		cout << i << " ";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

