#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Every element divisible by k

void solve() {
	ll n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;

	set<int> s;
	map<int,int> m;
	for (int i : a) {
		m[k - i%k]++;
		if (k-i%k != k)
			s.insert(k-i%k);
	}

	vector<int> u(all(s));
	ll largest = 1, index = 0;
	for (int i : u) {
		if (m[i] >= largest) {
			largest = m[i];
			index = i;
		}
	}

	cout << (largest-1)*k + index+(index?1:0) << "\n";
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

