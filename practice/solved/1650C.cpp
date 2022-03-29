#include <bits/stdc++.h>
using namespace std;
#define ll long long

// n is the number of nested segments required

struct Node {
	int weight;
	int pos;
	int index;
};

bool compWeight(Node first, Node second) {
	return first.weight < second.weight;
}

bool compPos(Node first, Node second) {
	return first.pos < second.pos;
}

void solve() {
	int n, m;
	cin >> n >> m;

	vector<Node> nodes;
	for (int i = 0,a,b; i < m; i++) {
		cin >> a >> b;
		Node temp;
		temp.pos = a;
		temp.weight = b;
		temp.index = i+1;
		nodes.push_back(temp);
	}

	sort(nodes.begin(),nodes.end(),compWeight);
	vector<Node> goodNodes;
	for (int i = 0; i < 2*n; i++)
		goodNodes.push_back(nodes[i]);

	sort(goodNodes.begin(),goodNodes.end(),compPos);

	ll total = 0;
	for (int i = 0; i < (int)goodNodes.size(); i++)
		total += goodNodes[i].weight;
	
	cout << total << "\n";

	for (int i = 0; i < n; i++) {
		cout << goodNodes[i].index << " " << goodNodes[2*n-1-i].index << "\n";
	}
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

