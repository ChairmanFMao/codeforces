#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// n is very small
// not beneficial to have b values 2e5 < b or -2e5 > b
// just brute force the first value of b and attempt to generate
// all of the other sequences that will satisfy a
// wa on test 2
// with sort, gets tle on test 1
// with optimisations it gets tle on test 4
// unsure on the approach, I think that I'm close but idk
// with optimisations more tle on test 4
// There might be a more efficient way to check or smth
// new method gets tle on test 2
// with an unordered_multiset still tle on test 2
// looked at tutorial and found this approach in the comments

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
	unordered_map<int,int,custom_hash> bdif;
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;

	for (int i = 0; i < n; i++)
		a[i] = abs(a[i]);

	for (int i = 0; i < n; i++)
		if (a[i] == 0) {
			cout << "YES\n";
			return;
		}

	set<int> s(all(a));
	if (sz(s) != n) {
		cout << "YES\n";
		return;
	}

	for (int i = 0; i < (1<<n)-1; i++) {
		int tot = 0;
		for (int j = 0; j < n; j++)
			if (i&(1<<j))
				tot += a[j];

		if (bdif[tot]) {
			cout << "YES\n";
			return;
		}

		bdif[tot] = 1;
	}

	cout << "NO\n";
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

