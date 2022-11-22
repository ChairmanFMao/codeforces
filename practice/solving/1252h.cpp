#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Need to create two buildings of A*B, output max A*B
// Need to be able to process queries in O(sqrt n) or O(log n)
// I don't think sqrt decomposotion works well here
// binary search and a prefix sum thing, just need to ensure
// that it won't include itself
// build up a prefix of the biggest secondary value for after
// store the two biggest values as there may be an index collision
// wa on test 8 on the first submission
// im not sure why it wouldn't work
// with some changes im now getting wa on test 7 -> wa on test 8
// tutorial literally says what im trying to implement
// wa on test 41 ;-;
// finally accepted, didn't need the binary search lol

// l will always be bigger than w
struct Land {
	ll l, w, id;
};

bool comp(Land a, Land b) {
	return a.l < b.l;
}

bool comp2(Land a, Land b) {
	return a.w < b.w;
}

void solve() {
	ll n;
	cin >> n;
	vector<Land> lands(n);
	Land land;
	for (int i = 0; i < n; i++) {
		cin >> land.l >> land.w;
		land.id = i;
		if (land.w > land.l)
			swap(land.w,land.l);
		lands[i] = land;
	}

	sort(all(lands),comp);

	vector<vector<Land> > bestAfter(n,vector<Land>(2));
	for (int i = 0; i < 2; i++) {
		bestAfter[n-1][i].l = 0;
		bestAfter[n-1][i].w = 0;
		bestAfter[n-1][i].id = -1;
	}

	for (ll i = n-2; ~i; i--) {
		bestAfter[i][0] = bestAfter[i+1][0];
		bestAfter[i][1] = bestAfter[i+1][1];
		if (lands[i+1].w >= bestAfter[i+1][0].w) {
			bestAfter[i][1] = bestAfter[i+1][0];
			bestAfter[i][0] = lands[i+1];
		} else if (lands[i+1].w >= bestAfter[i+1][1].w)
			bestAfter[i][1] = lands[i+1];
	}

	ll out = 0;

	for (int i = 0; i < n; i++) {
		// lower will be the valid one
		bool collide = bestAfter[i][0].id == lands[i].id;
		ll w1 = lands[i].w, w2 = bestAfter[i][collide].w;
		ll l1 = lands[i].l, l2 = bestAfter[i][collide].l;

		//cout << "w1: " << w1 << " w2: " << w2 << " l1: " << l1 << " l2: " << l2 << "\n";

		out = max(out, min(w1,w2) * min(l1,l2));
	}

	long double out2 = 0;
	for (Land i : lands)
		out2 = max(out2,((long double)(i.l*i.w))/2);

	cout << max((long double)out,out2) << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed;
	cout.precision(1);
	
	solve();
}

