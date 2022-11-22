#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Just a greedy sort of thing maybe?
// number of moves doesn't need to be minimised
// need to go a way that maximises score, kadane's algorithm
// also need to ensure that the score doesn't drop below 0
// just do a subarray sum from left to right, O(n) then greedy
// on all of the cases that work?
// calculate score to go to ends and gain each way
// requirements for each of the things?
// compact negatives to be next to each other and then calc
// might actually just be dp but, idk how to reduce from O(n^2)
// need sum over range >= 0, need to check that there is a valid
// order to do the moves
// unsure for dp, as it seems like the other side needs to be done
// to start each side
// ended up looking at tutorial
// we divide up the array in sections and we check if adding the
// left or right section will be allowed and if so we add it

const int mxN = 2e5;
int n, k;
vector<int> a(mxN);

void solve() {
	cin >> n >> k; k--;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	vector<ll> prefix(n+1,0);
	for (int i = 1; i <= n; i++)
		prefix[i] = prefix[i-1] + a[i-1];
	vector<pair<ll,ll>> rg, lg;
	ll prev = k+1;
	for (int i = k+2; i <= n; i++) {
		if (prefix[i] >= prefix[prev] || i == n) {
			ll smallest = 0, current = 0;
			for (int j = prev; j <= i-1; j++) {
				current += a[j];
				smallest = min(current,smallest);
			}
			rg.push_back({current,-smallest});
			prev = i;
		}
	}
	prev = k;
	for (int i = k-1; i >= 0; i--) {
		if (prefix[prev] >= prefix[i] || i == 0) {
			ll smallest = 0, current = 0;
			for (int j = prev-1; j >= i; j--) {
				current += a[j];
				smallest = min(current,smallest);
			}
			lg.push_back({current,-smallest});
			prev = i;
		}
	}

	reverse(all(lg));
	reverse(all(rg));

	ll val = a[k];
	while (1) {
		int moved = 0;
		if (sz(lg) && val >= lg.back().s) {
			val += lg.back().f;
			lg.pop_back();
			moved++;
		} if (sz(rg) && val >= rg.back().s) {
			val += rg.back().f;
			rg.pop_back();
			moved++;
		}

		if (sz(lg) == 0 || sz(rg) == 0) {
			cout << "YES\n";
			break;
		}
		if (!moved) {
			cout << "NO\n";
			break;
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

