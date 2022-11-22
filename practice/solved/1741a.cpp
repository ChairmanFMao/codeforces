#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// l = 1, m = 0, s = -1

void solve() {
	string a, b;
	cin >> a >> b;

	int vala = 0, valb = 0;
	for (int i = 0; i < sz(a); i++)
		if (a[i] == 'X')
			vala++;
	for (int i = 0; i < sz(b); i++)
		if (b[i] == 'X')
			valb++;

	if (a[sz(a)-1] == 'S')
		vala = -(vala+1);
	if (a[sz(a)-1] == 'L')
		vala++;

	if (b[sz(b)-1] == 'S')
		valb = -(valb+1);
	if (b[sz(b)-1] == 'L')
		valb++;

	cout << (vala == valb ? '=' : vala < valb ? '<' : '>') << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
		solve();
}

