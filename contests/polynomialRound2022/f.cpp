#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// The repeat operations just spawn in new pigs below kinda
// just shift all living ones down by sum of decrements so far
// This might be good with a segment tree potentially
// my current idea would be O(n^2) I think due to the shifting
// I'm trying to think of a way to do it more efficiently
// The shifting is the part in this idea that is slow
// when new pigs are spawned they won't be affected by repeats
// they will be affected by decrements
// might be like dp with a lazy segment tree
// once you get all the elements you need to shift them down
// we need to take advantage of the low health values
// In my current approach just the decrements would also take O(n)
// this could be accomplished with shifts?
// actually I don't think that would work
// I wrote up the O(n^2) code and it got a runtime error
// That was because I forgot to apply the mod everywhere
// Now I get tle on pretest 8
// Unsure how to do the decrement efficiently
// maybe use a queue? this would be O(n) still tho
// I can do the decrement efficiently if I am allowed O(n^2)
// for the memory complexity, however this doesn't pass
// maybe do this with a map?
// do lazy updates to all of the elements?
// unsure how this would help the decrement tho
// store ranges to clear and use a circular array?
// I don't think that lazy updates for the shifts would be that
// helpful
// lookup for this would be too slow
// I have looked at the editorial, it is very similar to what
// I was doing but, it just uses a map instead of an array
// We also need to do this thing with modular inverse for when
// we are doubling values
// This is actually a really cool way of solving the problem
const ll MOD = 998244353, mxX = 2e5;
map<ll,ll> m;

// This is to compute modular inverses efficiently
ll fastPow(ll base, ll exp) {
	base %= MOD;
	ll out = 1;
	for (;exp;exp>>=1) {
		if (exp&1)
			out = (out*base)%MOD;
		base = (base*base)%MOD;
	}
	return out;
}

void solve() {
	ll n, tot = 0;
	// These maintain some modular arithmetic stuff
	ll mul = 1, inv = 1;
	cin >> n;

	for (ll itr = 0; itr < n; itr++) {
		ll op; cin >> op;
		if (op == 1) {
			// This is the spawning of a new pig
			ll hp; cin >> hp;
			m[hp+tot] = (m[hp+tot]+inv)%MOD;
		} else if (op == 2) {
			// This is the decrement
			ll decrement; cin >> decrement;
			tot += decrement;
		}
		// This will be triggered at most O(log n) times once
		// there has been a decrement operation
		else if (tot <= mxX) {
			// This caters for when tot is still 0
			if (tot == 0) {
				mul = (mul*2)%MOD;
				inv = fastPow(mul,MOD-2);
			} else {
				// This is the shift upwards
				// we shift values up instead of down to have m
				// just increase upwards
				for (ll i = tot+mxX; i > tot; i--)
					m[i+tot] = (m[i+tot] + m[i])%MOD;
				tot += tot;
			}
		}
	}

	// This gets the total
	ll out = 0;
	for (ll i = tot+1; i <= tot+mxX; i++)
		out = (out + m[i])%MOD;

	// This takes care of all the multiplies by 2 at the start
	out = (out * mul) % MOD;

	cout << out << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

