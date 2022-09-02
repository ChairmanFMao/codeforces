#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// infinite fights, winner to front, loser to back
// up to 1e9 rounds, not really brute forceable
// all strength distinct
// we can process all of the rounds until strongest at front
// then we can just add the difference for the strongest
// eventually just gets to the person at the front staying there

bool comp(pair<int,pair<int,int>> a, pair<int,pair<int,int>> b) {
	return a.f < b.f;
}

void solve() {
	int n, q;
	cin >> n >> q;
	map<int,int> wins;
	deque<pair<int,int>> fight;
	int highest = 0, id = 0;
	for (int i = 0; i < n; i++) {
		pair<int,int> a;
		cin >> a.f;
		a.s = i;
		fight.push_back(a);
		if (a.f > highest) {
			highest = a.f;
			id = a.s;
		}
	}

	vector<pair<int,pair<int,int>> > queries(q);
	vector<int> out(q, 0);
	for (int i = 0; i < q; i++) {
		cin >> queries[i].s.f >> queries[i].f;
		queries[i].s.f--;
		queries[i].s.s = i;
	}
	sort(all(queries), comp);

	int time = 1, ptr = 0;
	while (fight.front().f != highest) {
		pair<int,int> fro = fight.front();
		fight.pop_front();
		pair<int,int> sec = fight.front();
		fight.pop_front();

		if (fro.f > sec.f) {
			wins[fro.s]++;
			fight.push_front(fro);
			fight.push_back(sec);
		} else {
			wins[sec.s]++;
			fight.push_front(sec);
			fight.push_back(fro);
		}

		while (queries[ptr].f == time) {
			out[queries[ptr].s.s] = wins[queries[ptr].s.f];
			ptr++;
		}
		time++;
	}

	while (ptr < q) {
		out[queries[ptr].s.s] = wins[queries[ptr].s.f];
		if (queries[ptr].s.f == id)
			 out[queries[ptr].s.s] += queries[ptr].f - time + 1;
		ptr++;
	}

	for (int i = 0; i < q; i++)
		cout << out[i] << "\n";
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

