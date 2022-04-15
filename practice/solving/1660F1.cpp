#include <bits/stdc++.h>
using namespace std;
#define ll long long

// problem with substrings like --- because there are two ways of making
// pluses but they are mutually exclusive
// Current algorithm is O(n^3) need to cache data somehow
// Managed to cache the number of doubles, pluses and minuses in arrays
// This solution passed in very good time!
// Algorithm is too slow to pass the harder version with bigger constraints

const int mxN = 3e3;
int m[mxN+1], p[mxN+1], doubles[mxN+1];
int n;
string s;
ll out;

void solve() {
	cin >> n >> s;
	out = 0;
	memset(m, 0, sizeof m);
	memset(p, 0, sizeof p);
	memset(doubles, 0, sizeof doubles);
	
	int subp = 0, subm = 0;
	for (int i = 0; i < n; i++) {
		if (s.substr(i,1) == "+")
			subp++;
		else
			subm++;

		m[i+1] = subm;
		p[i+1] = subp;
	}

	int subd = 0;
	for (int i = 0; i < n; i++) {
		doubles[i+1] = subd;
		if (i == n-1)
			break;
		if (s.substr(i,2) == "--")
			subd++;
	}

	for (int i = 0; i <= n; i++)
		for (int j = i+1; j <= n; j++) {
			int mdif = m[j] - m[i], pdif = p[j] - p[i];
			if (mdif == pdif)
				out++;
			if (mdif > pdif && (mdif-pdif)%3 == 0 && (mdif-pdif)/3 <= doubles[j] - doubles[i])
				out++;
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

