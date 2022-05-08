#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Only one type of unit can be chosen per battle
// O(n m) time complexity would time out I think - can't test every unit
// I made a brute force algorithm that works in O(n m) time - it works
// Times out on the 33rd test case now, long double data type exists
// Unsure how to further optimise the algorithm
// Looked at editorial for ideas, I think I can now solve it

const ll mxC = 1e6;
ll best[mxC+1];

void solve() {
	ll n, c, m;
	// clears all of best
	memset(best, 0, sizeof best);
	cin >> n >> c;
	// Takes in all of the warriors
	// Sets the best score for each value to the max possible
	for (ll i = 0,a,b,d; i < n; i++) {
		cin >> a >> b >> d;
		best[a] = max(best[a], b*d);
	}
	
	// For i going from 1 to c, we iterate upwards with j
	// we try to see if you can make a higher total with best[i] *(j/i)
	for (ll i = 1; i <= c; i++) {
		for (ll j = i; j <= c; j+=i) {
			best[j] = max(best[j],best[i]*(j/i));
		}
	}
	
	// This makes sure that the array is sorted and in ascending order
	for (ll i = 0; i < mxC; i++)
		best[i+1] = max(best[i+1],best[i]);

	cin >> m;
	// This takes in the enemies
	for (ll i = 0,a,b; i < m; i++) {
		cin >> a >> b;
		
		// This uses a binary search to find the first element greater than a*b
		ll out = upper_bound(best, best+mxC+1, a*b) - best;
		// if there was a higher value in the array it would output the
		// length of the array so we change that to -1, otherwise out
		cout << (out == mxC+1 ? -1 : out) << " ";
	}

}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cout << "\n";
	solve();
}

