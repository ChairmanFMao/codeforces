#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// R-L+1 must be odd, very important
// max of two xors I think due to it being odd
// can just xor everything and xor again
// if the sum of bits for all elements in the range is even
// then it only takes 1 query
// beneficial to use lengths of 3 and up
// when using ones of length 3 we are always able to win in 2
// xor over ranges we use must be 1
// if length is <= 2 and both not zero then not possible
// bits need to appear an even number of times
// if the length is odd or one end is zero then 1
// otherwise it will take 2
// if all 0 then just 0
// getting wa on test 2
// if length even, must xor to zero at some point in the middle
// otherwise it is not possible
// how to check for there being a point like that efficiently tho
// this zero must also be within a odd range
// could be done with precalc in O(n^2)
// need to check if a value is in a range in O(log n) somehow
// maybe do a sqrt decomposition with sets?
// not dealing with the fifth test case right
// wa on pretest 2 ;-;
// I think that with specific cases this could be O(n^2)
// getting a -1 when expected 1
// need to check the rest of the array isn't 0
// you only need to store two values for the xor of each
// now getting runtime error on test 3
// getting a status_access_violation, smth with pointers
// keep getting seg faults
// now getting wa on test 3, expected -1 found 2
// there must be some minor but somewhere
// now getting a new bug on some other test case
// need to store largest and smallest for each as could lead to
// a 1 instead of a 2
// getting a new status_access_violation and unsure why
// l: 98372 r: 199999 are causing the error
// getting -1 instead of 2
// might be possible with a map and binary search on sets
// this could be faster and easier to code
// might try this tomorrow

const ll big = 1e9;

struct INF {
	// Use each depending on (pos-l)%2 value
	pair<ll,ll> p = {1e9,-1e9};
	pair<ll,ll> p2 = {1e9,-1e9};
};

struct Part {
	map<ll,INF> m;
	ll length = 0, x = 0;
};

void solve() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	ll n = 2e5, q = 2e5;
	cin >> n >> q;
	vector<ll> a(n,1);
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
		//a[i] = rng()%big;
	}

	ll size = 1000;

	vector<ll> prefix(n+1,0);
	for (ll i = 1; i <= n; i++)
		prefix[i] = prefix[i-1] + a[i-1];

	vector<vector<ll> > prefix2(n+1,vector<ll>(30,0));
	for (ll i = 1; i <= n; i++)
		for (ll j = 0; j < 30; j++)
			prefix2[i][j] = prefix2[i-1][j] + (a[i-1]&(1<<j) ? 1 : 0);

	vector<ll> x(n,a[0]);
	for (ll i = 1; i < n; i++)
		x[i] = x[i-1] ^ a[i];

	vector<Part> parts;
	Part part;
	part.x = 0;
	part.m.clear();
	ll counter = 0;
	for (ll i = 0; i < n; i++) {
		part.x ^= a[i];
		// Store for each parity of i seperately
		if (i&1) {
			part.m[part.x].p.f = min(i,part.m[part.x].p.f);
			part.m[part.x].p.s = max(i,part.m[part.x].p.s);
		} else {
			part.m[part.x].p2.f = min(i,part.m[part.x].p2.f);
			part.m[part.x].p2.s = max(i,part.m[part.x].p2.s);
		}
		counter++;

		if ((!(i%size) && i) || i == n-1) {
			part.length = counter;
			parts.push_back(part);
			part.m.clear();
			part.x = 0;
			counter = 0;
		}
	}

	for (ll query = 0; query < q; query++) {
		ll l, r;
		cin >> l >> r;
		//l = rng()%(n-5)+1;
		//r = min((ll)(l+rng()%(n-5)),n);

		l--;
		r--;

		vector<ll> result(30,0);
		for (ll i = 0; i < 30; i++)
			result[i] = prefix2[r+1][i]-prefix2[l][i];

		ll flag = 0, bits = 0;
		for (ll i : result) {
			if (i&1) {
				cout << "-1\n";
				flag = 1;
				break;
			}
			bits += i;
		}
		if (flag)
			continue;

		if (bits == 0) {
			cout << "0\n";
			continue;
		}

		if (!((r-l)&1)) {
			cout << "1\n";
			continue;
		}

		// position starts at l
		ll pos = l, val = 0;
		int best = 3;
		while (pos%size && pos <= r) {
			val ^= a[pos];
			if (!val && (pos-l)%2==0) {
				if ((prefix[r+1]-prefix[pos+1] == 0 && r!=pos) || prefix[pos+1]-prefix[l] == 0)
					best = min(best,1);
				else
					best = min(best,2);
			}
			pos++;
		}

		// Does the sqrt bit
		ll partPos = pos/size;
		while (partPos < sz(parts) && pos+parts[partPos].length <= r) {
			// We want the values where the xor is val to get 0
			pair<ll,ll> i = parts[partPos].m[val].p;
			pair<ll,ll> i2 = parts[partPos].m[val].p2;
			if (i.f != 1e9) {
				if ((i.f-l)%2 == 0) {
					if ((prefix[r+1]-prefix[i.f+1] == 0 && r!=i.f) || prefix[i.f+1]-prefix[l] == 0)
						best = min(best,1);
					else
						best = min(best,2);
				}
			}
			if (i2.f != 1e9) {
				if ((i2.f-l)%2 == 0) {
					if ((prefix[r+1]-prefix[i2.f+1] == 0 && r!=i2.f) || prefix[i2.f+1]-prefix[l] == 0)
						best = min(best,1);
					else
						best = min(best,2);
				}
			}
			if (i.s != -1e9) {
				if ((i.s-l)%2 == 0) {
					if ((prefix[r+1]-prefix[i.s+1] == 0 && r!=i.s) || prefix[i.s+1]-prefix[l] == 0)
						best = min(best,1);
					else
						best = min(best,2);
				}
			}
			if (i2.s != -1e9) {
				if ((i2.s-l)%2 == 0) {
					if ((prefix[r+1]-prefix[i2.s+1] == 0 && r!=i2.s) || prefix[i2.s+1]-prefix[l] == 0)
						best = min(best,1);
					else
						best = min(best,2);
				}
			}
			
			pos += parts[partPos].length;
			val ^= parts[partPos].x;
			partPos++;
		}


		// Does the ending bit
		// The wrong answer error is within here
		// perhaps pos starts at the wrong value or smth?
		while (pos <= r) {
			val ^= a[pos];
			// The problem is probably with this if statement
			if (!val && (pos-l)%2==0) {
				if ((prefix[r+1]-prefix[pos+1] == 0 && r!=pos) || prefix[pos+1]-prefix[l] == 0)
					best = min(best,1);
				else
					best = min(best,2);
			}
			pos++;
		}

		bool right = (query==3)&&n==(2e5)&&q==(2e5)&&a[0]==992901318;
		cout << (best == 3 ? -1 : best) << '\n';
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

