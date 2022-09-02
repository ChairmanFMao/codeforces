#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Decrementing range queries?
// Potentially segement tree with lazy loading?
// Need to get final array and then remove the values
// and then check if any of them cause a flood
// Actually we only need to worry about peaks in the rainfall,
// we could just store all of these values?
// If just storing peaks we may get up to n^2 values
// sort and then see how the peaks effect each other
// I think the solution is O(n^2) ;-;

struct Node {
	ll total;
	map<ll,ll> effect;
};

struct op {
	ll f, s, o;
};

bool comp(op a, op b) {
	return a.f < b.f;
}

void solve() {
	ll n, m;
	cin >> n >> m;
	vector<op> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].f >> a[i].s;
		a[i].o = i;
	}
	
	sort(all(a),comp);

	vector<Node> nodes(n);
	for (int i = 0; i < n; i++) {
		ll left = i-1, right = i+1;
		nodes[i].total += a[i].s;
		nodes[i].effect[i] = a[i].s;
		while (left >= 0) {
			ll value = max(0ll,a[left].s - abs(a[i].f-a[left].f));
			nodes[i].effect[left] = value;
			nodes[i].total += value;
			left--;
		}
		while (right < n) {
			ll value = max(0ll,a[right].s - abs(a[i].f-a[right].f));
			nodes[i].effect[right] = value;
			nodes[i].total += value;
			right++;
		}
	}

	vector<int> floods;
	for (int i = 0; i < n; i++)
		if (nodes[i].total > m)
			floods.push_back(i);

	vector<int> out(n);
	for (int i = 0; i < n; i++) {
		int flag = 1;
		for (int j : floods) {
			if (nodes[j].total - nodes[j].effect[i] > m) {
				flag = 0;
				break;
			}
		}
		out[a[i].o] = flag;
	}

	for (int i : out)
		cout << i;
	cout << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
		solve();
}

