#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Searching for all others with negative versions of their gradients

struct Person {
	int x, y, u, v;
};

void solve() {
	int n;
	cin >> n;
	vector<Person> a(n);
	for (Person& i : a)
		cin >> i.x >> i.y >> i.u >> i.v;

	ll out = 0;
	map<long double,int> grad;
	for (int i = 0; i < n; i++) {
		if (a[i].v == 0)
			grad[1e10]++;
		else {
			long double tmp = a[i].u/(long double)a[i].v;
			grad[tmp]++;
			out += grad[tmp ? -tmp : 1e10];
		}
	}
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

