#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Need there to be 4 distinct indices where
// ax + ay = az + aw
// There is a perculiar bound on the total of a 2.5e6
// maximum value of the sum is 5e6
// maximum value of n is 2e5
// a difference between two numbers has to occur twice
// with 4 distinct numbers
// i.e. 1, 4 and 2, 5
// maybe just dp with a map?
// this could lead to O(n sqrt(n)) I think
// I think that this might timeout
// it did end up getting tle on test 4
// it failed with n = 1000 ish
// tle on test 8 with an improved approach
// if we just make a set it can be much faster
// still tle on test 8 even with a set
// Tried using pragmas to see if I could get the code to go
// faster

struct Two {
	int f, s, fi, si;
};

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;

	map<int,pair<int,int>> last;
	for (int i = 0; i < n; i++) {
		if (last[a[i]].f < i+1) {
			last[a[i]].s = last[a[i]].f;
			last[a[i]].f = i+1;
		} else if (last[a[i]].s < i+1)
			last[a[i]].s = i+1;
	}

	set<int> s(all(a));

	map<int,vector<Two>> m;
	for (int i = 0; i < n; i++) {
		for (int itr : s) {
			vector<int> ve = {last[itr].f-1,last[itr].s-1};
			for (int j : ve) {
				if (j <= i)
					continue;
				Two temp;
				temp.f = a[i]; temp.fi = i+1;
				temp.s = a[j]; temp.si = j+1;
				int v = a[i] + a[j];
				m[v].push_back(temp);
				for (int k = 0; k < sz(m[v]); k++) {
					for (int l = k+1; l < sz(m[v]); l++) {
						set<int> s = {m[v][k].fi,m[v][k].si,m[v][l].fi,m[v][l].si};
						if (sz(s) == 4) {
							cout << "YES\n" << m[v][k].fi << " " << m[v][k].si << " " << m[v][l].fi << " " << m[v][l].si << "\n";
							return;
						}
					}
				}
			}
		}
	}
	cout << "NO\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

