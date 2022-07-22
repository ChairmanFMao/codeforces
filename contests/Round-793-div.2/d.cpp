#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<pair<int,int>> edge;
	vector<int> adj(n, 0);

	int out = 0;
	for (char c : s)
		out += c == '0' ? 2 : 1;

	if (out > n-1) {
		cout << "NO\n";
		return;
	}

	int one = 0;
	for (char c : s)
		out += (int)(c == '1');

	if (one < 2) {
		cout << "NO\n";
		return;
	}

	int parity = (n-1) & 1, hub = 0;
	for (int i = 0; i < n; i++)
		if ((s[i] & 1) == parity) {
			hub = i;
			break;
		}

	for (int i = 0; i < n; i++) {
		if (s[i] == '0') {
			edge.push_back({(i+n-1)%n,i});
			edge.push_back({i,i+1});
		} else {
			
		}
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

