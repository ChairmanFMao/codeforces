#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

bool comp(pair<int,int> a, pair<int,int> b) {
	return a.s-a.f > b.s-b.f;
}

void solve() {
	int n;
	cin >> n;
	vector<pair<int,int>> p(n);
	for (pair<int,int>& i : p)
		cin >> i.f;
	for (pair<int,int>& i : p)
		cin >> i.s;

	sort(all(p),comp);
	int left = 0, right = n-1, out = 0;
	while (left < right) {
		if (p[left].s+p[right].s >= p[left].f+p[right].f) {
			out++;
			left++;
			right--;
		} else
			right--;
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

