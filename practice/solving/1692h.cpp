#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// We should store the power of 2 they get to rather than the actual number
// Could just store where the next occurances of the numbers occur
// Carry on going until the power of 2 is negative
// Looked at the test case that was failing, just needed a <= rather than a <

void solve() {
	int n;
	cin >> n;
	vector<int> x(n);
	for (int& i : x)
		cin >> i;

	set<int> s;
	// The index is the number, the vector is where it occurs
	map<int,vector<int> > m;
	for (int i = 0; i < n; i++) {
		s.insert(x[i]);
		m[x[i]].push_back(i);
	}

	vector<int> u(all(s));
	int best = INT_MIN, start = 0, end = 0, number = 0;
	for (int i : u) {
		int score = 0, location = m[i][0]-1, starting = m[i][0];
		for (int j : m[i]) {
			score++;
			score -= j - location;
			score++;
			if (score <= 0) {
				starting = j;
				score = 1;
			}
			if (score > best) {
				number = i;
				best = score;
				start = starting;
				end = j;
			}
			location = j;
		}
	}

	cout << number << " " << start+1 << " " << end+1 << "\n";
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

