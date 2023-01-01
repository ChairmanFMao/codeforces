#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// This seems really similar to the problem yesterday
// Its kinda subtly different tho
// only one person is eliminated in each round
// we only need to care about the two extremes
// There is always one person that can't win at one extreme
// Somehow this passes pretests, unsure of its proof

void solve() {
	ll n;
	string s;
	cin >> n >> s;

	ll current = 1;
	cout << "1 ";
	for (ll i = 1; i < sz(s); i++) {
		if (s[i] != s[i-1])
			current = i+1;
		cout << current << " ";
	}
	cout << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
		solve();
}

