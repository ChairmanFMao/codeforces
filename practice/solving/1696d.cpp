#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// I looked at editorial and understand what needs to be done
// Basically you have to go through the ai where ai = n point and you
// can solve recursively
// I also took most of implementation from ksun48
const int mxN = 3e5;
int a[mxN], preMax[mxN], preMin[mxN], sufMax[mxN], sufMin[mxN], location[mxN], n, out;

void recur(int lower, int upper) {
	int minV = location[lower ? sufMin[lower] : preMin[upper]];
	int maxV = location[lower ? sufMax[lower] : preMax[upper]];

	if (minV > lower && minV < upper) {
		out++;
		recur(lower, minV);
		recur(minV, upper);
	} else if (maxV > lower && maxV < upper) {
		out++;
		recur(lower, maxV);
		recur(maxV, upper);
	}
}

void solve() {
	out = 1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i]; a[i]--;
		location[a[i]] = i;
		preMax[i] = 0; preMin[i] = INT_MAX; sufMax[i] = 0; sufMin[i] = INT_MAX;
	}

	preMin[0] = a[0]; preMax[0] = a[0];
	for (int i = 1; i < n; i++) {
		preMin[i] = min(preMin[i-1], a[i]);
		preMax[i] = max(preMax[i-1], a[i]);
	}

	sufMin[n-1] = a[n-1]; sufMax[n-1] = a[n-1];
	for (int i = n-2; ~i; i--) {
		sufMin[i] = min(sufMin[i+1], a[i]);
		sufMax[i] = max(sufMax[i+1], a[i]);
	}

	if (n == 1) {
		cout << "0\n";
		return;
	}

	recur(0, n-1);
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

