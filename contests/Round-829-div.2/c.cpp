#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// sum of all of the segments partitions should be zero
// maybe dp?
// I think the only case where it is not possible is when
// a sums to an odd number
// just greedily go until partition sums to zero
// never beneficial to have streaks longer than 2,
// just split into smaller ones of length 2
// I think dp might be good here
// need to use traceback to generate all of the partitions
// unsure if dp would work, can't take optimal easily
// every streak of two can disappear
// difference for c2 is that we can flip some of the lone ones
// if they have a zero before them
// flipping them still changes the total by 2
// pairs starting with zero are better than dupe pairs
// scan for normal pairs then check for zero pairs
// I had a load of silly errors and got lots of wa

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;

	int tot = 0;
	for (int i : a)
		tot += i;
	if (tot % 2) {
		cout << "-1\n";
		return;
	}

	int other = 0;
	vector<pair<int,int> > up, down, p, out;
	vector<int> seen(n,0);
	
	for (int i = n-1; i >= 0; i--) {
		if (i < n-1 && a[i] == a[i+1] && a[i] != 0 && !seen[i] && !seen[i+1]) {
			seen[i] = 1;
			seen[i+1] = 1;
			if (a[i] == 1)
				up.push_back({i,i+1});
			else if (a[i] == -1)
				down.push_back({i,i+1});
			i++;
		}
	}

	for (int i = 0; i < n; i++) {
		if (i < n-1 && a[i] == 0 && a[i+1] != 0 && !seen[i] && !seen[i+1]) {
			seen[i] = 1;
			seen[i+1] = 1;
			p.push_back({i,i+1});
			i++;
		}
	}

	for (int i = 0; i < n; i++)
		if (!seen[i]) {
			out.push_back({i,i});
			other += a[i];
		}

	// ones in p can go +1 or -1, no way to go 0
	// needs to work with what up and down can produce
	
	for (int i = 0; i < sz(p); i++) {
		if (other > 0) {
			if (a[p[i].s] == -1) {
				out.push_back({p[i].f,p[i].f});
				out.push_back({p[i].s,p[i].s});
			} else
				out.push_back(p[i]);
			other--;
		} else {
			if (a[p[i].s] == 1) {
				out.push_back({p[i].f,p[i].f});
				out.push_back({p[i].s,p[i].s});
			} else
				out.push_back(p[i]);
			other++;
		}
	}
	
	for (int i = 0; i < sz(up); i++) {
		if (other < 0) {
			out.push_back({up[i].f,up[i].f});
			out.push_back({up[i].s,up[i].s});
			other += 2;
		} else
			out.push_back(up[i]);
	}
	for (int i = 0; i < sz(down); i++) {
		if (other > 0) {
			out.push_back({down[i].f,down[i].f});
			out.push_back({down[i].s,down[i].s});
			other -= 2;
		} else
			out.push_back(down[i]);
	}

	if (other) {
		cout << "-1\n";
		return;
	}

	cout << sz(out) << "\n";
	sort(all(out));
	for (pair<int,int> i : out)
		cout << i.f+1 << " " << i.s+1 << "\n";
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

