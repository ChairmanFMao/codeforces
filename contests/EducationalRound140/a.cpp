#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Just check if there is a right angle?

void solve() {
	vector<pair<ll,ll> > pos(3);
	for (pair<ll,ll>& i : pos)
		cin >> i.f >> i.s;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int other = 3-i-j;
			if (i == j || other == i || other == j)
				continue;
			if (pos[other].f == pos[i].f && pos[other].s == pos[j].s) {
				cout << "NO\n";
				return;
			}
		}
	}
	cout << "YES\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
		solve();
}

