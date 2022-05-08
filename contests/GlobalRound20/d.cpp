#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// Solution needs to be quite efficient
// look for transferring numbers to the left first
// brute force might lead to O(n^2) time
// We don't need to do full rotations - we can do it with smaller sections
// Move them to the next location outside of the zone could be done
// with a binary search maybe

void solve() {
	int n;
	cin >> n;
	vector<pair<int,int>> a(n);
	vector<int> b(n);
	for (pair<int,int>& i : a) {
		cin >> i.first;
		i.second = 1;
	}
	for (int& i : b)
		cin >> i;

	map<int,deque<int>> occur;
	for (int i = 0; i < n; i++)
		occur[a[i].first].push_back(i);

	int bptr = 0;
	for (int i = 0; i < n; i++) {
		while (a[i].second > 0) {
			while (i < n && a[i].first != b[bptr]) {
				if (sz(occur[a[i].first]) == 0) {
					i++;
					continue;
				} if (sz(occur[a[i].first]) == 1) {
					if (a[occur[a[i].first].front()].second > 0 && occur[a[i].first].front() < i) {
						break;
					} else {
						cout << "NO\n";
						return;
					}
				}
				int tmp = occur[a[i].first].front();
				occur[a[i].first].pop_front();
				int tmp2 = occur[a[i].first].front();
				a[tmp2].second += a[tmp].second;
				a[tmp].second = 0;
				i++;
			}
		}

		int tmp = occur[a[i].first].front();
		a[tmp].second--;
		if (a[tmp].second <= 0)
			occur[a[i].first].pop_front();
		bptr++;
	}
	cout << "YES" << "\n";;
}

int main(void) {
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	
	cout << "\n";
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
		solve();
}

