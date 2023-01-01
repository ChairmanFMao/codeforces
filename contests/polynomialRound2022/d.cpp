#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Unsure what to do to check if cases are valid
// Check if the number of ones is divisible by n
// Need to decide how to distribute 1s from rows with more to
// rows with less
// rows with less can receive ones on multiple columns
// unsure exactly how to do the matching
// I'm not sure if a greedy will work
// Actually I think that it would
// I think the solution will be O(m n) or smth

void solve() {
	ll n, m;
	cin >> n >> m;
	vector<vector<ll> > grid(n,vector<ll>(m));
	for (vector<ll>& i : grid)
		for (ll& j : i)
			cin >> j;

	ll tot = 0;
	vector<ll> rowTot(n,0);
	for (ll i = 0; i < n; i++)
		for (ll j = 0; j < m; j++) {
			tot += grid[i][j];
			rowTot[i] += grid[i][j];
		}

	// This caters for the invalid cases
	if (tot%n) {
		cout << "-1\n";
		return;
	}

	// This is how many 1s we want in each row
	ll desired = tot/n;
	vector<vector<ll> > columnNeed(m);
	for (ll i = 0; i < n; i++) {
		if (rowTot[i] >= desired)
			continue;
		for (ll j = 0; j < m; j++)
			if (!grid[i][j])
				columnNeed[j].push_back(i);
	}

	vector<pair<pair<ll,ll>,ll> > out;
	for (ll i = 0; i < n; i++) {
		if (rowTot[i] <= desired)
			continue;
	
		for (ll j = 0; j < m && rowTot[i] > desired; j++) {
			while (sz(columnNeed[j])) {
				ll current = columnNeed[j][sz(columnNeed[j])-1];
				if (rowTot[current] >= desired)
					columnNeed[j].pop_back();
				else
					break;
			}
			if (grid[i][j] && sz(columnNeed[j])) {
				ll current = columnNeed[j][sz(columnNeed[j])-1];
				out.push_back({{i,current},j});
				rowTot[i]--;
				rowTot[current]++;
				grid[i][j] = 0;
				grid[current][j] = 1;
				columnNeed[j].pop_back();
			}
		}
	}

	cout << sz(out) << "\n";
	for (ll i = 0; i < sz(out); i++) {
		cout << out[i].f.f+1 << " " << out[i].f.s+1 << " " << out[i].s+1 << "\n";
	}
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

