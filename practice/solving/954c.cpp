#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Just a number matrix, rectangle, along lines first
// Need to check for jumps greater than 1
// I did this without editorial as well :)

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& i : a) {
		cin >> i; i--;
	}

	set<int> jumps;
	for (int i = 0; i < n-1; i++)
		jumps.insert(abs(a[i]-a[i+1]));

	vector<int> u(all(jumps));
	if (sz(u) > 2) {
		cout << "NO\n";
			return;
	}
	int current = -1;
	for (int i : u)
		if (i != 1)
			current = i;

	if (!current) {
		cout << "NO\n";
		return;
	}

	if (current == -1) {
		cout << "YES\n1 " << *max_element(all(a))+1 << "\n";
		return;
	}

	int x = current, y = (*max_element(all(a))+current-1)/current;
	int xc = a[0]%x, yc = a[0]/x;
	for (int i = 1; i < n; i++) {
		int nx = a[i]%x, ny = a[i]/x;
		if (abs(nx-xc) + abs(ny-yc) < 2) {
			xc = nx;
			yc = ny;
	 	} else {
			cout << "NO\n";
			return;
		}
	}

	cout << "YES\n" << y+1 << " " << x << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

