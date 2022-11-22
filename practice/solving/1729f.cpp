#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// minimise l1 then l2
// Only the number in the units column matters
// I think you can just precalc all of the mod values?
// sum of all the digits in that range mod 9 can use prefix sums

void solve() {
	string s;
	cin >> s;
	int w, m;
	// w is a constant
	cin >> w >> m;
	map<int,vector<int> > mapping;
	vector<int> prefix(sz(s)+1,0);
	for (int i = 1; i <= sz(s); i++)
		prefix[i] = prefix[i-1] + s[i-1]-48;
	for (int i = w-1; i < sz(s); i++)
		mapping[(prefix[i+1]-prefix[i-w+1])%9].push_back(i+1-w);
	for (int q = 0; q < m; q++) {
		int l, r, k; cin >> l >> r >> k; l--;
		int mult = (prefix[r]-prefix[l])%9, flag = 1;
		int l1 = INT_MAX, l2 = INT_MAX;
		for (int i = 0; i < 9 && flag; i++) {
			if (sz(mapping[i]) >= 2)
				if ((i * mult + i)%9==k) {
					if (mapping[i][0] < l1 || (mapping[i][0] == l1 && mapping[i][1] < l2)) {
						l1 = mapping[i][0];
						l2 = mapping[i][1];
					}
				}
			for (int j = 0; j < 9 && flag; j++) {
				if (i == j)
					continue;
				if (!sz(mapping[i]) || !sz(mapping[j]))
					continue;

				if ((i * mult + j)%9==k) {
					if (mapping[i][0] < l1 || (mapping[i][0] == l1 && mapping[j][0] < l2)) {
						l1 = mapping[i][0];
						l2 = mapping[j][0];
					}
				}
			}
		}
		cout << (l1==INT_MAX?-1:l1+1) << " " << (l2==INT_MAX?-1:l2+1) << "\n";
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

