#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// I'm not sure that my approach works lol

const ll dy[4] = {0,0,1,-1}, dx[4] = {1,-1,0,0};

struct State {
	set<pair<ll,ll> > s;
	vector<vector<ll> > grid;
	ll id;
};

bool comp(State f, State s) {
	return sz(f.s) > sz(s.s);
}

void solve() {
	ll n, m, k;
	cin >> n >> m >> k;
	vector<State> states(k+1);
	for (ll i = 0; i <= k; i++) {
		vector<vector<ll> > grid(n,vector<ll>(m));
		set<pair<ll,ll> > possible;
		for (ll j = 0; j < n; j++) {
			string s;
			cin >> s;
			for (ll l = 0; l < m; l++)
				grid[j][l] = s[l]&1;
		}

		for (ll j = 1; j < n-1; j++) {
			for (ll l = 1; l < m-1; l++) {
				ll val = 4 - 4*grid[j][l], other = 0;
				for (ll itr = 0; itr < 4; itr++)
					other += grid[j+dy[itr]][l+dx[itr]];

				if (other == val)
					possible.insert({j,l});
			}
		}
		State tmp;
		tmp.s = possible;
		tmp.id = i+1;
		tmp.grid = grid;
		states[i] = tmp;
	}

	sort(all(states),comp);

	vector<pair<ll,ll> > out;
	for (ll i = 0; i < sz(states)-1; i++) {
		for (ll j = 0; j < n; j++) {
			for (ll l = 0; l < m; l++) {
				if (states[i].grid[j][l] != states[i+1].grid[j][l]) {
					out.push_back({j,l});
				}
			}
		}

		out.push_back({-2,-states[i+1].id});
	}

	cout << states[0].id << "\n";
	cout << sz(out) << "\n";
	for (ll i = 0; i < sz(out); i++) {
		if (out[i].f < 0)
			cout << "2 " << -out[i].s << "\n";
		else
			cout << "1 " << out[i].f+1 << " " << out[i].s+1 << "\n";
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

