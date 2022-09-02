#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// A set of utensils is 3 of them

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;

	map<int,int> m;
	set<int> s;
	for (int i : a) {
		m[i]++;
		s.insert(i);
	}
	vector<int> u(all(s));
	int highest = 0;
	for (int i : u)
		highest = max(highest,m[i]+((k-(m[i]%k))%k));

	int out = 0;
	for (int i : u)
		out += highest - m[i];

	cout << out << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

