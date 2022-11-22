#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Need to also generate operations
// wa on test 2 somehow
// still wa on pretest 2 even after corrections
// didn't read the q properly
// just move all of one character to the start/end
// just move all a characters to the end
// still wa on test 2 somehow
// just get all the n before a
// finally got it :)

void solve() {
	int n;
	cin >> n;

	string s = "";
	for (int i = 0; i < n; i++)
		s += "BAN";

	queue<int> q;
	for (int i = 0; i < sz(s) && sz(q) < (n+1)/2; i++)
		if (s[i] == 'A')
			q.push(i);

	cout << sz(q) << "\n";
	for (int i = sz(s)-1; ~i && sz(q); i--)
		if (s[i] == 'N') {
			cout << q.front()+1 << " " << i+1 << "\n";
			q.pop();
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

