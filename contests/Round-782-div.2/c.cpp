#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// This greedy approach gets wa on pretest 2
// I think there are some occasions where it is optimal to not move the
// capital all the way to the end of the empire

void solve() {
	ll n, a, b;
	cin >> n >> a >> b;
	vector<ll> numbers(n);
	for (ll& i : numbers)
		cin >> i;

	ll capital = 0, cost = 0;
	cost += numbers[0]*b;
	
	for (int i = 0; i < n-1; i++) {
		if (a*(numbers[i] - capital) < (n-i-1)*b*(numbers[i] - capital)) {
			cost += a*(numbers[i]-capital);
			capital = numbers[i];
		}
		cost += b*(numbers[i+1] - capital);
	}

	cout << cost << "\n";
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

