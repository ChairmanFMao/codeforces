#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Do shifts and check which are possible
// I think O(n^2) would pass here
// getting lower than expected
// Unsure about this problem
// Always consider the worst case scenario
// Need to get a unique configuration of two characters x apart
// and maximise the chances of this happening
// Looked at editorial, I had the same idea
// all I needed was a mod in line 40 ;-;
// the mod idea isn't stated in the problem

void solve() {
	string s;
	cin >> s;
	int n = sz(s);
	
	map<int,vector<int>> m;
	for (int i = 0; i < n; i++)
		m[s[i]].emplace_back(i);

	long double out = 0;
	// Just need to iterate over all of the characters
	for (int i = 97; i < 97+26; i++) {
		if (!sz(m[i]))
			continue;
		// Finding the best value for j
		// where you can uniquely identify the most of them
		int best = 0;
		for (int j = 1; j < n; j++) {
			int current = 0;
			map<int,int> occurs;
			for (int k : m[i]) {
				char c = s[(k+j)%n];
				occurs[c]++;
			}
			for (auto k = occurs.begin(); k != occurs.end(); k++)
				if (k->s == 1)
					current++;
			best = max(best,current);
		}

		out += (long double)best;
	}


	cout << out/n << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout << setprecision(10);
	
	solve();
}

