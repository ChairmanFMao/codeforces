#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// I'm thinking about a segment tree being needed
// Need lines that start after top and end before bottom
// For part two, quadratic time complexity will not work
// Need something with log n update for range and log n access

const int mxN = 2e5;
ll segment[mxN+mxN+10];
ll n;

// This stuff is kinda copied from the CSES book
// Its just a normal segment tree

void add(int index) {
	index += n;
	segment[index]++;
	for (index>>=1; index >= 1; index>>=1)
		segment[index] = segment[index+index] + segment[index+index+1];
}

ll Sum(int start, int index) {
	index += n;
	start += n;
	ll out = 0;
	while (start <= index) {
		if (start&1)
			out += segment[start++];
		if (!(index&1))
			out += segment[index--];
		index>>=1;
		start>>=1;
	}

	return out;
}

void solve() {
	memset(segment, 0, sizeof segment);
	cin >> n;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;

	ll out = 0;
	for (int i = 0; i < n; i++) {
		ll value = Sum(a[i],n);
		out += value;
		add(a[i]);
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

