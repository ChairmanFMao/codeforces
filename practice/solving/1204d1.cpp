#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Just need to ensure that sequences are the same for all queries
// can be done in a brute force way in O(n^2)
// however, actually checking each one will be O(n^3)
// the bits of t are just some subset of the bits of s
// just iterate through all the 1 bits and check if works off
// I don't think you can query with lis through a segtree
// all of the different bits interact with each other in queries
// for a lis there are 3 formats:
// all zero
// all one
// some zero then some one - need to know optimum time to switch
// if you could binary search over this...
// potentially if we can process the queries for lis in O(log n)
// then we could just do a brute force O(n^2 log n) approach
// if a character is at the start of a lis it can always be 0
// might not be able to treat operations independently
// want to be able to make the lis with just zeros then greedy
// need to greedily remove more 1s to reduce the lis to original
// I think I was very close to being there ;-;
// I just needed to check the lis before and after changing
// characters, lis of the whole string
// gets tle on test 2

int lis(string s) {
	vector<int> one(sz(s)+1,0), zero(sz(s)+1,0);
	for (int i = 1; i <= sz(s); i++) {
		one[i] = one[i-1] + (s[i-1]&1);
		zero[i] = zero[i-1] + !(s[i-1]&1);
	}

	int longest = 0;
	for (int i = 0; i <= sz(s); i++)
		longest = max(longest, zero[i] + one[sz(s)]-one[i]);

	return longest;
}

void solve() {
	string s;
	cin >> s;
	int n = sz(s);
	
	int one = 0, zero = 0;
	for (char c : s) {
		if (c&1)
			one++;
		else
			zero++;
	}
	
	int value = lis(s);

	for (int i = 0; i < n; i++) {
		if (s[i] == '0')
			continue;

		s[i] = '0';
		if (lis(s) != value)
			s[i] = '1';
	}

	cout << s << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

