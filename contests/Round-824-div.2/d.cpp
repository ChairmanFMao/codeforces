#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// bounds for n and k are very low, maybe brute force of a kind
// some dp thing I think
// A set is 3 cards and a group is 5 cards
// need to have either distinct or same for each column
// 2^20 ~= 1e7
// There would be one dp dimension for 0,1,2,distinct for each
// This would however lead to 4^20 at worst case
// There needs to be at least 2 distinct columns for all the 5
// cards in each group to be distinct
// The two sets in the metaset need at least one common card
// need to somehow generate all possible sets then overlap?
// check each one for sets in O(n * k!)
// sum of all 3 cards in a set must be divisible by 3 in each column
// we could just iterate over pairs and work out what the last one
// would need to be
// gets weird if there is 2 or 1
// this current method is O(n^3) I think

void solve() {
	int n, k;
	cin >> n >> k;
	vector<vector<int> > cards(n,vector<int>(k));
	for (vector<int>& i : cards)
		for (int& j : i)
			cin >> j;

	map<vector<int>,int> m;
	for (int i = 0; i < n; i++)
		m[cards[i]] = i;

	vector<int> val(n,0);
	map<int, vector<pair<int,int>>> pairs;
	map<int, set<int>> lookup;
	int out = 0;
	for (int i = 0; i < n; i++) {
		int sets = 0;
		for (int j = i+1; j < n; j++) {
			vector<int> tot(k);
			for (int l = 0; l < k; l++)
				tot[l] = (k*3 - (cards[i][l] + cards[j][l]))%3;

			// to make the set we need tot
			if (m[tot] > j) {
				sets++;
				if (lookup[i].count(j) + lookup[i].count(m[tot]) == 0) {
					pairs[i].push_back({j,m[tot]});
					lookup[i].insert(j);
					lookup[i].insert(m[tot]);
				}
				if (lookup[j].count(i) + lookup[j].count(m[tot]) == 0) {
					pairs[j].push_back({i,m[tot]});
					lookup[j].insert(i);
					lookup[j].insert(m[tot]);
				}
				if (lookup[m[tot]].count(i) + lookup[m[tot]].count(j) == 0) {
					pairs[m[tot]].push_back({i,j});
					lookup[m[tot]].insert(i);
					lookup[m[tot]].insert(j);
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
		out += (sz(pairs[i]) * (sz(pairs[i])-1))/2;

	cout << out << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	solve();
}

