#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// You want the lowest to be & of all queries
// then you can derive the higher ones later
// build from right to left
// getting wa test 4
// statement not true rather than not optimal solution
// unsure why this is not working
// I found a way to unsure I don't get optimal solution
// but it should still work to get correct values
// looked at editorial, they just do it with each bit individually
// I get what they are doing, kinda quite different to my solution

const int mxN = 1e5;
vector<vector<pair<int,int> > > adj(mxN);
vector<int> out(mxN);

void solve() {
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		adj[i].clear();
		out[i] = INT_MAX;
	}

	for (int i = 0; i < q; i++) {
		int a, b, c; cin >> a >> b >> c; a--; b--;
		adj[a].push_back({b,c});
		adj[b].push_back({a,c});
	}
	

	for (int b = 30; ~b; b--) {
		// Removes any of the bits if edges don't have them
		for (int i = 0; i < n; i++) {
			for (pair<int,int> j : adj[i])
				if (!(j.s & (1<<b)))
					out[i] &= ~(1 << b);
		}

		// Checks if there are any extra bits that can be removed
		for (int i = 0; i < n; i++)
			if (out[i] & (1 << b)) {
				out[i] &= ~(1 << b);
				for (pair<int,int> j : adj[i]) {
					// If the edge doesn't contain it and the total does contain it, the bit must be set
					if (!(out[j.f] & (1 << b)) && (j.s & (1 << b))) {
						out[i] |= 1 << b;
						break;
					}
				}
			}
	}

	for (int i = 0; i < n; i++)
		cout << out[i] << " ";
}

int main(void) {
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	
	solve();
}

