#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// getting wa on pretest 2
// I think that there might be some edge cases with negs
// just trying to preserve zeros at the end of the string
// something to do with sums between occurances of 0
// want to cancel out previous total and account for next total
// still get wa on pretest 2 with a different approach
// need to try to find some edge case
// found an edge case where it should be 2 rather than 1
// there is some sort of pay off calculation
// get the most common value in the range and change to - that
// need to treat all of the ranges independently
// still wa on test case 2 sadly

void solve() {
	ll n;
	cin >> n;
	n++;
	vector<ll> a(n,0);
	for (ll i = 0; i < n-1; i++)
		cin >> a[i];

	vector<ll> zero;
	for (ll i = 0; i < n; i++)
		if (!a[i])
			zero.push_back(i);

	ll out = 0;
	// We know that there will be at least 1 zero as we are adding
	// one at the end anyway
	ll stot = 0;
	for (ll i = 0; i < zero[0]; i++)
		stot += a[i];
	a[zero[0]] -= stot;

	vector<pair<ll,ll> > p;
	for (ll i = 0; i < sz(zero)-1; i++)
		p.push_back({zero[i],zero[i+1]});

	for (ll i = 0; i < sz(p); i++) {
		ll tot = 0, best = 1, val = 0, current = 0;
		map<ll,ll> m;
		// This needed to be here ;-;
		m[0] = 1;
		for (ll j = p[i].f+1; j < p[i].s; j++) {
			current += a[j];
			m[current]++;
			if (m[current] > best) {
				best = m[current];
				val = current;
			}
			tot += a[j];
		}
		
		a[p[i].f] -= val;
		a[p[i].s] += val-tot;
		//out += best;
	}

	// This just gets the output efficiently
	ll tot = 0;
	for (ll i = 0; i < n-1; i++) {
		tot += a[i];
		if (!tot)
			out++;
	}

	/*
	cout << "a: ";
	for (ll i : a)
		cout << i << " ";
	cout << "\n";
	*/

	cout << out << "\n";
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

