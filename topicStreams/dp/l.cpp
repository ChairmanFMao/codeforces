#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// dp over n and then over k?
// There is a greedy solution here actually
// Passed with the greedy solution

struct Group {
	int cost;
	int size;
	int id;
};

bool comp (Group f, Group s) {
	return f.cost == s.cost ? f.size < s.size : f.cost > s.cost;
}

bool comp2 (pair<int,int> f, pair<int,int> s) {
	return f.first < s.first;
}

void solve() {
	// How many groups are there
	int n;
	cin >> n;
	// The size of the group and how much they pay
	vector<Group> people(n);
	for (int i = 0; i < n; i++) {
		people[i].id = i+1;
		cin >> people[i].size >> people[i].cost;
	}
	// How many tables there are
	int k;
	cin >> k;
	// How many people can sit at each table
	vector<pair<int,int> > r(k);
	for (int i = 0; i < k; i++) {
		cin >> r[i].first;
		r[i].second = i+1;
	}

	vector<bool> used(k,0);
	sort(all(r),comp2);
	sort(all(people),comp);

	vector<pair<int,int> > output;
	int out = 0, count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			if (used[j])
				continue;
			if (r[j].first >= people[i].size) {
				out += people[i].cost;
				count++;
				used[j] = 1;
				output.push_back({people[i].id,r[j].second});
				break;
			}
		}
	}
	
	cout << count << " " << out << "\n";
	for (pair<int,int> i : output)
		cout << i.first << " " << i.second << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

