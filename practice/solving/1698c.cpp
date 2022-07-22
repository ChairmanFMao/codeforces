#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// Had to look at editorial, needed to simplify the problem

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;

	int pos = 0, neg = 0;
	for (int i : a) {
		if (i>0)
			pos++;
		if (i<0)
			neg++;
	}

	if (pos>=3 || neg>= 3) {
		cout << "NO\n";
		return;
	}

	vector<int> b;
	sort(all(a));
	for (int i = 0; i < 3; i++) {
		if (a[i] >= 0)
			break;
		b.push_back(a[i]);
	}

	for (int i = sz(a)-1; i > sz(a)-4; i--) {
		if (a[i] <= 0)
			break;
		b.push_back(a[i]);
	}

	int count = 0;
	for (int i : a)
		if (!i && count < 2) {
			b.push_back(i);
			count++;
		}

	set<int> lookup(all(b));
	for (int i = 0; i < sz(b); i++) {
		for (int j = i+1; j < sz(b); j++) {
			for (int k = j+1; k < sz(b); k++) {
				if (!lookup.count(b[i] + b[j] + b[k])) {
					cout << "NO\n";
					return;
				}
			}
		}
	}
	cout << "YES\n";
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

