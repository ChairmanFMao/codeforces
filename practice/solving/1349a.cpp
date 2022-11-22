#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Something to do with splitting everything into prime factors
// For every pair we need to get the lcm, the gcd of these lcms
// will just have to have every factor in
// all have or all but one have would lead to it being added
// now getting wa on test 14, unsure how
// multiplying by 13 one too many times
// finally got it when I iterated over primes first

vector<int> primes;

bool prime(int n) {
	for (int i : primes)
		if (!(n%i))
			return 0;
	return 1;
}

ll power(ll base, ll exp) {
	ll out = 1;
	for (; exp > 0; exp>>=1) {
		if (exp&1)
			out *= base;
		base *= base;
	}
	return out;
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;

	for (int i = 2; i <= 2e5; i++)
		if (prime(i))
			primes.emplace_back(i);

	vector<vector<int>> factorised(sz(primes),vector<int>(2));
	for (int i = 0; i < sz(primes); i++)
		factorised[i] = {INT_MAX,INT_MAX};

	map<int,int> m;
	for (int i : a)
		m[i]++;

	ll out = 1;
	for (int i = 0; i < sz(primes); i++) {
		vector<int> v;
		for (auto j = m.begin(); j != m.end(); j++) {
			int val = j->f, current = 0;
			while (!(val%primes[i])) {
				current++;
				val/=primes[i];
			}
			for (int k = 0; k < min(j->s,2); k++) {
				if (!sz(v))
					v.push_back(current);
				else if (sz(v) == 1) {
					if (current > v[0])
						v.push_back(current);
					else {
						v.push_back(v[0]);
						v[0] = current;
					}
				} else {
					if (current < v[0]) {
						v[1] = v[0];
						v[0] = current;
					} else if (current < v[1]) {
						v[1] = current;
					}
				}
			}
			if (sz(v) == 2 && v[0]+v[1] == 0)
				break;
		}

		if (sz(v) == 1)
			out *= power(primes[i],v[0]);
		else {
			if (v[0] == v[1])
				out *= power(primes[i],v[0]);
			else
				out *= power(primes[i],v[1]);
		}
	}

	cout << out << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	solve();
}

