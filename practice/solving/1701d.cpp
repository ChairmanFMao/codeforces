#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// i / a = b, i/(b+1) < a <= i/b
// I read tutorial, watched newton school video and looked at tourist solution
// You basically sort by the ending boundary for each range of possible numbers
// You can do this easily by using a set as a priority queue
// Each time we pop the element with the smallest max point and
// assign its value to the out array as well as eraseing it from the set
// also I thought the " \n"[i == n-1] was a really cool trick on
// tourist's solution

void solve() {
	int n;
	cin >> n;
	vector<int> b(n);
	for (int& i : b)
		cin >> i;

	vector<vector<pair<int,int> > > segments(n+1);
	for (int i = 0; i < n; i++) {
		int min = (i+1)/(b[i]+1) + 1, max = n;
		if (b[i])
			max = (i+1)/b[i];
		
		segments[min].push_back({max,i});
	}

	vector<int> out(n);
	// Here we are using a set like a priority queue
	set<pair<int,int> > currentSegments;
	for (int i = 1; i <= n; i++) {
		for (pair<int,int> j : segments[i])
			currentSegments.insert(j);

		out[currentSegments.begin()->second] = i;
		currentSegments.erase(currentSegments.begin());
	}

	for (int i = 0; i < n; i++)
		cout << out[i] << " \n"[i==n-1];
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

