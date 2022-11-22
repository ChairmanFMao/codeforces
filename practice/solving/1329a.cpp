#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// All colours to appear at least once
// All cells should be coloured
// An O(n^2) solution will not be good enough here
// need to choose where operations are used
// just greedily place operations and if there is a new colour move to the right one square
// I think this would be O(n), need to be able to preserve rarer colours
// if it is the last occurance of the colour put it down and move on?
// if any overlap with a last occurance it is not possible
// all cells must also be coloured, need to do this with overflow?
// you may not always have sufficient overflow to colour them all
// might need to cramp them until you get enough
// variable extra to tell what ptr should jump by
// just check if the output can be made by biggest/last occurances of all of them
// If so we spread them out like that?
// otherwise we need to fill the last bit with extra
// need to allocate to the last occurances from back to front
// just place junk at the back, as far as possible going towards the good on the left
// can also greedily generate where the left ones need to go
// there are i distinct colours
// I have been doing a more complicated problem ;-;
// wa on test 4
// Just put them all of the left and move to right and see if it
// intersects with itself, if so then we can break

void solve() {
	ll n, m;
	cin >> n >> m;
	vector<ll> a(m);
	for (ll& i : a)
		cin >> i;

	ll total = 0;
	for (ll i : a)
		total += i;

	if (total < n || m-1+a[m-1] > n) {
		cout << "-1\n";
		return;
	}

	vector<ll> out(m);
	for (ll i = 0; i < m; i++)
		out[i] = i+1;

	ll back = n+1;
	for (ll i = m-1; ~i; i--) {
		ll right = a[i]+i;
		if (back-a[i] <= i+1)
			break;
		back -= a[i];
		out[i] = back;
	}

	for (ll i = 0; i < m; i++)
		if (out[i] + a[i]-1 > n) {
			cout << "-1\n";
			return;
		}

	for (ll i : out)
		cout << i << " ";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

