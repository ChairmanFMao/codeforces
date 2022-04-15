#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Looked at solution because I was doing it a really bad way

int solve2(string n, string ending) {
	int back = n.size()-1, out = 0;

	while (back >= 0 && n[back] != ending[1]) {
		back--;
		out++;
	}

	int second = back-1;
	while (second >= 0 && n[second] != ending[0]) {
		second--;
		out++;
	}

	return back != -1 && second != -1 ? out : 1e9;
}

void solve() {
	ll n;
	cin >> n;
	int out = 1e9;
	
	string end[] = {"00","25","50","75"};
	for (int i = 0; i < 4; i++)
		out = min(out,solve2(to_string(n), end[i]));
	
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

