#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()
#define f first
#define s second

// Can calculate the number needed to buy at full price
// Need to figure out how many over should be bought
// I don't think the binary search condition holds
// Looked at solution but I was very close in the first place

bool comp(pair<ll,ll> a, pair<ll,ll> b) {
	return a.s > b.s;
}

void solve() {
	int n;
	cin >> n;
	vector<pair<ll,ll> > products(n);
	for (pair<ll,ll>& i : products)
		cin >> i.f >> i.s;

	sort(all(products),comp);
	ll out = 0, bought = 0, back = n-1;
	for (int i = 0; i < back; i++) {
		ll current = min(products[i].f,products[back].s-bought);
		out += current * 2;
		bought += current;
		products[i].f -= current;
		
		for (int j = back; j >= i; j--) {
			if (bought >= products[j].s) {
				out += products[j].f;
				bought += products[j].f;
				products[j].f = 0;
				back--;
			} else
				break;
		}

		// This little line was why my code didn't pass ;-;
		if (products[i].f)
			i--;
	}

	for (int i = n-1; ~i; i--) {
		if (bought >= products[i].s)
			out += products[i].f;
		else if (bought + products[i].f > products[i].s) {
			out += (products[i].s - bought) * 2;
			out += bought + products[i].f - products[i].s;
		} else
			out += 2*products[i].f;

		bought += products[i].f;
	}

	cout << out << "\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}


