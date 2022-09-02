#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Kinda like a graph almost

bool comp(string a, string b) {
	return sz(a) < sz(b);
}

void solve() {
	int n;
	cin >> n;
	vector<string> a(n);
	for (string& i : a)
		cin >> i;

	sort(all(a),comp);

	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			int flag = 0;
			for (int k = 0; k <= sz(a[j])-sz(a[i]); k++)
				if (a[i] == a[j].substr(k,sz(a[i])))
					flag = 1;

			if (!flag) {
				cout << "NO\n";
				return;
			}
		}
	}

	cout << "YES\n";
	for (string s : a)
		cout << s << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

