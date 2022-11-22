#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

void solve() {
	string s;
	cin >> s;

	map<int,int> m;
	queue<int> q;
	for (char c : s) {
		q.push(c-48);
		m[c-48]++;
	}

	stack<int> out;
	map<int,int> stored;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < stored[i]; j++) {
			out.push(i);
			m[i]--;
		}
		while (sz(q) && m[i]) {
			int current = q.front();
			q.pop();
			if (current == i) {
				out.push(current);
				m[i]--;
				continue;
			}
			m[current]--;
			m[min(current+1,9)]++;
			stored[min(current+1,9)]++;
		}
	}

	vector<int> output(sz(out), 0);
	for (int i = sz(out)-1; ~i; i--) {
		output[i] = out.top();
		out.pop();
	}

	for (int i : output)
		cout << i;
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

