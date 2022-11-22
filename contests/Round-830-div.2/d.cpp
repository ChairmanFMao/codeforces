#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Iteration would lead to O(n^2) solution
// just do some precomputation for low values of k?
// this wouldn't work, if so it would just be a cheese
// what if we process the queries offline and just store the kmex
// for all of the k that we know are coming
// getting memory limit exceeded
// still mle even with the clears
// somehow memoise for multiples of each other?
// unsure how to make the code faster and not timeout
// might need to rethink my approach entirely
// this was like a massive cheese

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void solve() {
	ll q;
	cin >> q;
	vector<pair<ll,ll> > ops;
	vector<ll> k;
	for (int i = 0; i < q; i++) {
		char c; ll a; cin >> c >> a;
		if (c == '?')
			k.push_back(a);
		ops.push_back({c=='?',a});
	}
	
	unordered_map<ll,ll,custom_hash> m;
	unordered_map<ll,unordered_set<ll,custom_hash>,custom_hash> m2;
	for (ll i : k) {
		m[i] = i;
		m2[i].insert(i);
	}

	unordered_set<ll,custom_hash> s;
	for (int i = 0; i < q; i++) {
		// This handles ? queries
		if (ops[i].f) {
			cout << m[ops[i].s] << "\n";
			continue;
		}
	
		// This will handle + queries
		s.insert(ops[i].s);
		for (auto j = m2[ops[i].s].begin(); j != m2[ops[i].s].end(); j++) {
			ll current = ops[i].s;
			while (s.count(current))
				current += *j;
			m[*j] = current;
			m2[current].insert(*j);
		}
		m2.erase(ops[i].s);
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	solve();
}

