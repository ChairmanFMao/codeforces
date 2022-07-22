#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// WA on pretest 7 currently, unsure where the error is
// Kinda annoyed but still debugging
// This won't work well! - there is O(n^2) potential
// I think that this will timeout
// Problem is very long strings like 1 1 2 3 4 5 6 7 8 9 10
// My nice solution turns out to actually not work
// Thinking about encoding the bits with numbers and using numbers
// for addition and carry over, but it proabably wouldn't work well

void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for (int& i : a)
		cin >> i;

	map<int,int> m;
	priority_queue<int> pq;
	priority_queue<int, vector<int>, greater<int>> small;
	for (int i : a) {
		pq.push(i);
		small.push(i);
		m[i]++;
	}

	for (int i = 0; i < q; i++) {
		int k, l; cin >> k >> l; k--;
		m[a[k]]--;
		a[k] = l;
		pq.push(l);
		m[l]++;

		int biggest = pq.top(), smallest = small.top();
		while (!m[biggest]) {
			pq.pop();
			biggest = pq.top();
		}
		while (!m[smallest]) {
			small.pop();
			smallest = small.top();
		}

		int out = biggest, start = smallest;
		vector<int> past(biggest+25-smallest,0);
		for (int i = 0; i < biggest+20-smallest; i++) {
			past[i] += m[start+i];
			past[i+1] += past[i]/2;
			if (past[i])
				out = max(out,i+start);
		}

		cout << out << "\n";
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

