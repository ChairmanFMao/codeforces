#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Could use a priority queue and stuff
// Just need smallest element to be on one of the ends
// Smallest amount of moves is just the max element of the array


void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;

	map<int,deque<int>> m;
	for (int i = 0; i < n; i++)
		m[a[i]].push_back(i);

	priority_queue<int,vector<int>,greater<int>> q;
	int left = 0, right = n-1;

	for (int i : a)
		q.push(i);

	for (int i = 0; i < n; i++) {
		int current = q.top();
		q.pop();
		if (m[current].front() == left) {
			left++;
			m[current].pop_front();
		} else if (m[current].back() == right) {
			right--;
			m[current].pop_back();
		} else {
			cout << "NO\n";
			return;
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

