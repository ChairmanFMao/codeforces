#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// Looked at tourist's solution
// Just a dfs with some optimisation
// Can acutally be done using bfs, just looked at tutorial

bool invalid(string s) {
	for (char c : s)
		if (c >= 50)
			return 0;
	return 1;
}

ll best = 1e18, x, n;
void dfs(ll number, ll operations) {
	string s = to_string(number);
	if (sz(s) == n) {
		best = min(operations,best);
		return;
	}
	ll temp = number, minimum = 0;
	while (sz(to_string(temp)) < n) {
		temp *= 9;
		minimum++;
	}
	if (invalid(s) || operations + minimum >= best)
		return;

	set<int> contains;
	for (char c : s)
		contains.insert(c-48);
	for (int i = 9; i >= 2; i--)
		if (contains.count(i))
			dfs(number * i, operations+1);
}

void solve() {
	best = 1e18;
	cin >> n >> x;
	
	dfs(x,0);

	cout << (best == 1e18 ? -1 : best) << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

