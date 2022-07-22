#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// This epicly got accepted, I thought of the solution myself after the
// contest finished :facepalm:

const int mxN = 5e3;

// Quadratic time complexity leads to TLE on test 5
// n is quite small on the scale of things
int l[mxN][mxN+1];
int r[mxN][mxN+1];

void solve() {
	int n;
	cin >> n;
	vector<int> p(n);
	for (int& i : p)
		cin >> i;

	for (int i = 0; i < n; i++) {
		memset(l[i], 0, sizeof l[i]);
		memset(r[i], 0, sizeof r[i]);
		for (int j = 0; j < i; j++)
			l[i][p[j]]++;
		
		for (int j = 1; j <= n; j++)
			l[i][j] += l[i][j-1];

		for (int j = i+1; j < n; j++)
			r[i][p[j]]++;

		for (int j = 1; j <= n; j++)
			r[i][j] += r[i][j-1];
	}

	ll out = 0;
	// This is pb
	for (int i = 1; i < n; i++) {
		// This is pc
		for (int j = i+1; j < n; j++) {
			// This is pa
			int a = r[j][p[i]];
			// This is pd
			int d = l[i][p[j]];
			out += a * d;
		}
	}
	
	cout << out << "\n";
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

