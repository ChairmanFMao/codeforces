#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;

	// We are taking from end of a to middle of b
	// then from middle of b to end of c
	// Trying to achieve ascending order
	// You need to make it so that the smallest elements are in the middle
	// The middle moves which really sucks
	
	vector<pair<int,int> > rep;
	for (int i = n-1; i > 0; i-=2) {
		rep.push_back({a[i],a[i-1]});
	}
	if (n & 1)
		rep.push_back({0,a[0]});

	vector<int> out;
	for (int i = sz(rep)-1; i >= 0; i--) {
		if (rep[i].first == 0) {
			out.push_back(rep[i].second);
		} else {
			out.push_back(min(rep[i].first,rep[i].second));
			out.push_back(max(rep[i].first,rep[i].second));
		}
	}

	for (int i = 0; i < n-1; i++) {
		if (out[i] > out[i+1]) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
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

