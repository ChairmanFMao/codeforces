#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Just visit everyone between in the alphabet

void solve() {
	string s;
	cin >> s;

	int first = s[0]-97, last = s[sz(s)-1]-97;
	map<int,vector<int> > m;
	for (int i = 1; i < sz(s)-1; i++) {
		m[s[i]-97].emplace_back(i);
	}
	
	vector<int> out;
	if (first < last)
		for (int i = first; i <= last; i++)
			for (int j : m[i])
				out.emplace_back(j);
	else
		for (int i = first; i >= last; i--)
			for (int j : m[i])
				out.emplace_back(j);

	cout << abs(first-last) << " " << sz(out)+2 << "\n1 ";
	for (int i : out)
		cout << i+1 << " ";
	cout << sz(s) << "\n";
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

