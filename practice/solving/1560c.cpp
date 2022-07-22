#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

void solve() {
	int k;
	cin >> k;

	int start = (int)sqrt(k);
	if (start * start != k)
		start++;

	int current = start * start - k;
	if (current >= start) {
		cout << start-(current-start+1) << " " << start << "\n";
	} else {
		cout << start << " " << current+1 << "\n";
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

