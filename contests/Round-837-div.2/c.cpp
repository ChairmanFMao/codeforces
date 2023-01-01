#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// check if the gcd is not equal to 1
// we want to check for any pair if the gcd is not equal to 1
// prime factorise each and use a dict?
// wa on pretest 2
// getting tle
// This is O(n * sqrt(1e9)) which is too large ig
// iterate over every prime and check if they are divisible
// still around the same complexity I think
// if there are a lot of large primes it times out
// two numbers when modded by the same prime are 0
// unsure how to do this without prime factorisation
// need to do something that involves n rather than values?
// I think this is more efficient and will work
// It passes even tho its a little slow

vector<ll> primes;

void genPrimes() {
	primes.push_back(2);
	for (ll i = 3; i*i <= 1e9; i++) {
		ll flag = 1;
		for (ll j : primes)
			if (!(i%j)) {
				flag = 0;
				break;
			}

		if (flag)
			primes.push_back(i);
	}
}

void solve() {
	ll n;
	cin >> n;
	vector<ll> a(n);
	for (ll& i : a)
		cin >> i;

	map<ll,ll> m;
	for (ll i = 0; i < n; i++) {
		ll tmp = a[i];
		for (ll j : primes) {
			if (j*j > tmp)
				break;

			ll flag = 0;
			while (!(tmp%j)) {
				tmp /= j;
				flag = 1;
			}

			if (flag) {
				if (m[j] > 0) {
					cout << "YES\n";
					return;
				}
				m[j]++;
			}
		}
		if (tmp != 1) {
			if (m[tmp] > 0) {
				cout << "YES\n";
				return;
			}
			m[tmp]++;
		}
	}
	cout << "NO\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	genPrimes();
	
	cout << "\n";
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
		solve();
}

