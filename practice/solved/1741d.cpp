#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Isn't this kinda like bubble sort lol
// All of them should be in pairs with each other
// just store the lowest and highest in pairs, linear time

void solve() {
	int m;
	cin >> m;
	vector<int> a(m);
	for (int& i : a)
		cin >> i;

	// First element for depth
	// First stores the lowest, second stores highest
	vector<pair<int,pair<int,int>>> b(m+m);
	for (int i = m; i < m+m; i++)
		b[i] = {1,{a[i-m],a[i-m]}};

	ll out = 0;
	for (int i = m-1; i > 0; i--) {
		if (max(abs(b[i+i+1].s.f - b[i+i].s.s),abs(b[i+i+1].s.s - b[i+i].s.f)) != b[i+i+1].f+b[i+i].f-1) {
			cout << "-1\n";
			return;
		}
		if (b[i+i].s.s > b[i+i+1].s.s)
			out++;
		b[i] = {b[i+i+1].f+b[i+i].f,{min(b[i+i].s.f,b[i+i+1].s.f), max(b[i+i].s.s,b[i+i+1].s.s)}};
		if (b[i].f == m)
			break;
	}

	cout << out << "\n";
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

