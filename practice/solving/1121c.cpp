#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// The contraints of the problem make it look brute forceable
// Can't really think of a suitable data structure
// Currently overestimating for last test case

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;

	// This will store the indexes of the elements to be decremented
	queue<int> q;
	for (int i = 0; i < min(n,k); i++)
		q.push(i);
	// This stores the current value of all the elements
	vector<int> c(n,0);
	vector<int> interest(n,0);
	int ptr = k, done = 0;
	
	while (!q.empty()) {
		int i = sz(q), add = 0;
		while (i--) {
			int current = q.front();
			q.pop();
			c[current]++;
			if (c[current] == round(100 * done/(double)n))
				interest[current] = 1;
			if (c[current] == a[current]) {
				add++;
				if (ptr < n) {
					q.push(ptr);
					ptr++;
				}
			} else if (c[current] < a[current])
				q.push(current);
		}
		done += add;
	}

	int out = 0;
	for (int i : interest)
		out += i;
	cout << out << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

