#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Integers need to be distinct
// max^2 - 2*max*min + min^2 = sum
// (max - min)^2 = sum
// we can manipulate the expression algebraically
// difference between max and min needs to be at least n-1
// the sum will be at least (n*(n+1))/2
// the sum also needs to be a square number
// I think I have a solution for when n is even
// just choose the next even square above n
// I need to think of a way of adapting this for odd n
// I found a way for 5
// 6 9 10 11 13
// 7*6 + 7
// 3*14 + 7
// for 7
// 6 10 11 14 12 13 15
// 10*11 + 11
// 5*22 + 11
// 10*12 + 1
// 5*24 + 1
// 8 19 -> 27
// 94 in 7
// wa on pretest 2

void solve() {
	ll n;
	cin >> n;

	if (!(n&1)) {
		ll down = n-1, up = n+1;
		for (ll i = 0; i < n/2; i++) {
			cout << down << " " << up << " ";
			down--; up++;
		}
		cout << "\n";
		return;
	}

	ll lower = n+1, upper = n+2, tot = (n+1)*(n+1);
	vector<ll> out;
	for (ll i = 0; i < n/2; i++) {
		out.push_back(lower);
		out.push_back(upper);
		tot -= lower; tot -= upper;
		lower--; upper++;
	}
	out.push_back(tot);
	out[sz(out)-2]++;
	out[sz(out)-3]--;
	for (ll i : out)
		cout << i << " ";
	cout << "\n";
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

