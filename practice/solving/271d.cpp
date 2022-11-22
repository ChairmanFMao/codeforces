#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Very cool string hashing problem
// I now use two hashes to make the strings more unique
// might need to use an unordered set to make it faster
// I just needed to use the unordered set and big primes for
// string hashing to get the code to pass

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
	string s, good;
	int k;
	cin >> s >> good >> k;
	int n = sz(s);

	set<char> bad;
	for (int i = 0; i < 26; i++)
		if (!(good[i]&1))
			bad.insert(97+i);

	vector<ll> p(n+1,1), q(n+1,1);
	ll pVal = 31, qVal = 37, pMOD = 1880032837071527, qMOD = 9422583095595119;
	for (int i = 1; i <= n; i++) {
		q[i] = (q[i-1] * qVal) % qMOD;
		p[i] = (p[i-1] * pVal) % pMOD;
	}

	unordered_set<ll,custom_hash> seen;
	for (int i = 0; i < n; i++) {
		// We are kinda incrementally hashing the strings to get
		// O(n^2) rather than O(n^3)
		ll score = 0, hash = 0, hash2 = 0;
		for (int j = i; j < n; j++) {
			if (bad.count(s[j]))
				score++;
			if (score > k)
				break;
			hash = (hash + (s[j] - 'a' + 1) * p[j-i]) % pMOD;
			hash2 = (hash2 + (s[j] - 'a' + 1) * q[j-i]) % qMOD;
			if (!seen.count(hash+hash2))
				seen.insert(hash+hash2);
		}
	}

	cout << sz(seen) << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

