#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// Weights can change by 1, if desired

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;

	sort(all(a),greater<int>());

	map<int,int> seen;
	int out = 0;
	for (int i : a) {
		if (!seen[i+1]) {
			seen[i+1] = 1;
			out++;
		} else if (!seen[i]) {
			seen[i] = 1;
			out++;
		} else if (!seen[i-1] && i > 1) {
			seen[i-1] = 1;
			out++;
		}
	}

	cout << out << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

