#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;

	deque<int> out;
	map<int,int> m;
	for (int i : a) {
		if (m[i] > 0)
			continue;

		if (sz(out) < k) {
			m[i]++;
			out.push_front(i);
		} else {
			out.push_front(i);
			m[i]++;
			m[out.back()]--;
			out.pop_back();
		}
	}

	cout << sz(out) << "\n";
	while (sz(out)) {
		cout << out.front() << " ";
		out.pop_front();
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

