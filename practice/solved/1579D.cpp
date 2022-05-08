#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
	int n;
	cin >> n;
	vector<pair<int,int>> numbers;
	for (int i = 1,a; i <= n; i++) {
		cin >> a;
		if (a)
			numbers.push_back({a,i});
	}

	sort(numbers.begin(),numbers.end());
	// Priority queues are kinda weird, always make a max heap, less here means that it should be in descending order
	priority_queue<pair<int,int>,vector<pair<int,int>>, less<pair<int,int>>> q;
	for (int i = (int)numbers.size()-1; ~i; i--)
		q.push(numbers[i]);

	vector<pair<int,int>> out;

	while ((int)q.size() > 1) {
		pair<int,int> f = q.top();
		q.pop();
		pair<int,int> s = q.top();
		q.pop();
		out.push_back({f.second,s.second});
		f.first--;
		s.first--;
		if (s.first)
			q.push(s);
		if (f.first)
			q.push(f);
	}

	cout << out.size() << "\n";
	for (pair<int,int>& i : out)
		cout << i.first << " " << i.second << "\n";
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

