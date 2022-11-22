#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Just realised that they come one by one rather than all together
// Just need to keep updating a map I think
// problem is when all are set but you have another that isn't needed
// wa test 2, had some errors with the index

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n),b(n),c(m);
	for (int& i : a)
		cin >> i;
	for (int& i : b)
		cin >> i;
	for (int& i : c)
		cin >> i;
	
	int index = -1;
	for (int i = 0; i < n; i++) {
		if (b[i] == c[m-1])
			index = i;
		if (b[i] == c[m-1] && a[i] != b[i]) {
			index = i;
			break;
		}
	}
	if (index == -1) {
		cout << "NO\n";
		return;
	}

	map<int,queue<int> > needed;
	for (int i = 0; i < n; i++)
		if (a[i] != b[i] && i != index)
			needed[b[i]].push(i);

	vector<int> out(m);
	for (int i = 0; i < m-1; i++) {
		if (sz(needed[c[i]])) {
			out[i] = needed[c[i]].front();
			needed[c[i]].pop();
		} else
			out[i] = index;
	}
	out[m-1] = index;

	set<int> s(all(b));
	vector<int> u(all(s));
	for (int i : u)
		if (sz(needed[i])) {
			cout << "NO\n";
			return;
		}

	cout << "YES\n";
	for (int i : out)
		cout << i+1 << " ";
	cout << "\n";
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

