#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// At least one serious student in the row/column
// just need to avoid getting O(m n) algorithm
// Brute force could be done in O(m n^2) I think
// I was thinking that you could do something with gaps for rows
// My current algorithm has a few off by one errors
// The calculations that I do for the rows don't actually work
// m different states for each row
// I think they can be calculated in O(m) with some prefix sums
// I believe it can be done in O(m n) to calculate for each line at each
// time point
// I ended up looking at the editorial, I got the columns bit right yet,
// I nearly got the rows.

void solve() {
	ll n, m;
	string s;
	cin >> n >> m >> s;
	// Stores the sum of each column
	ll out = 0;
	queue<int> columns;
	for (int i = 0; i < m; i++)
		columns.push(0);

	vector<int> rows(sz(s),0);
	ll last = INT_MIN;
	for (ll i = 0; i < sz(s); i++) {
		int current = s[i] - 48;
		// This does all of the columns
		int currentColumn = columns.front();
		columns.pop();
		if (!currentColumn && current)
			out++;
		columns.push((int)(currentColumn || current));

		// This does all of the rows
		if (current)
			last = i;
		// This works because the rows will be set back to their original
		// state after m moves with a new row added
		if (i-last < m)
			rows[i%m]++;
		cout << rows[i%m] + out << " ";
	}
	cout << "\n";
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

