#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Something O(n^2) could work here
// We can generate all the strings in O(n^2) I think
// Unsure of how to find maximal sub-palindrome
// can't use Manacher's algorithm
// if we do generate them all then we need something that is less
// than O(n) to find the maximal sub-palindrome
// order of the characters matters
// O(n^3) will not be viable
// I'm not even sure of a way to get the sub-palindrome in O(n)
// only destinations should be ones that end with the same as the
// starting character I think
// extras added on don't effect the answer
// maybe even something like dp?
// store last used and available on each end?
// just search from every node and store the ones we have
// can also just be nodes in the middle without a partner
// just store the open in a stack or smth?
// also don't bother storing each side, as well will have checked
// all combinations of them anyway
// need to come up with a way to have it comeback on itself
// need to make it do the max better
// getting 4 for the first test case somehow
// This got wa on pretest 2
// current code works for samples but doesn't do it right

const ll mxN = 2e3;
vector<vector<ll> > adj(mxN+1);
ll out = 0, n;
string s;

vector<char> v;
stack<char> st, trace;
ll start = 0;
void dfs(ll node, ll parent, ll val) {
	if (val > out) {
		cout << "start: " << start << " node: " << node << " parent: " << parent << " val: " << val << "\n";
	}
	if (start == 9 && node == 4 && parent == 2) {
		cout << "promising: " << val << "\n";
		stack<char> tmp;
		while (sz(trace)) {
			tmp.push(trace.top());
			trace.pop();
		}
		cout << "trace: " << "\n";
		while (sz(tmp)) {
			cout << tmp.top() << " ";
			trace.push(tmp.top());
			tmp.pop();
		}
		cout << "\n";
	}
	out = max(val,out);

	// Checks for if we can do a pairing
	ll len = 0;
	for (ll i = sz(v)-1; i >= 0; i--) {
		if (s[node] == v[i]) {
			trace.push(v[i]);
			st.push(v[i]);
			v.pop_back();
			len++;
			out = max(out,val+2+(len>1&&!val?1:0));
			for (ll u : adj[node])
				if (u != parent)
					dfs(u,node,val+2+(len>1&&!val?1:0));
			trace.pop();
			break;
		}
		st.push(v[i]);
		v.pop_back();
		len++;
	}

	v.push_back(s[node]);
	// Restores back to original state
	for (ll i = 0; i < len; i++) {
		v.push_back(st.top());
		st.pop();
	}

	for (ll u : adj[node])
		if (u != parent)
			dfs(u,node,val);
	
	v.pop_back();
}

void solve() {
	out = 0;
	cin >> n >> s;
	for (ll i = 0; i < n; i++)
		adj[i].clear();
	for (ll i = 0; i < n-1; i++) {
		ll a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (ll i = 1; i <= n; i++) {
		start = i;
		dfs(i,-1,0);
	}

	cout << out << "\n";
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

