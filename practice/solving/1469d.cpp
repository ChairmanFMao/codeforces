#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// ai = i
// n-1 times 1 and 1 times 2
// cap of n+5 steps
// I think I have a solution in n+6 steps ;-;
// idea doesn't work because it uses one more 1 than I want
// Finally got it with 64 increment
// There is an easier way of just fixing 8 and removing all other

class comp {
	public:
		bool operator() (pair<int,int> a, pair<int,int> b){
			return a.f < b.f;
		}
};

void solve() {
	int n;
	cin >> n;
	
	vector<pair<int,int> > out;
	int mult = 64, current = 2;
	set<int> s;
	while (current < 200000) {
		s.insert(current);
		current *= mult;
	}

	priority_queue<pair<int,int>, vector<pair<int,int>>, comp> q;
	for (int i = 2; i < n; i++) {
		if (s.count(i)) {
			q.push({i,i});
			continue;
		}
		out.push_back({i,n});
	}
	q.push({n,n});

	while (sz(q) > 1) {
		pair<int,int> a = q.top();
		q.pop();
		pair<int,int> b = q.top();
		q.pop();
		if (a.f == 2 && b.f == 1)
			break;
		out.push_back({a.s,b.s});
		a.f = (a.f + b.f - 1) / b.f;
		q.push(a);
		q.push(b);
	}

	cout << sz(out) << "\n";
	for (pair<int,int> i : out)
		cout << i.f << " " << i.s << "\n";
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

