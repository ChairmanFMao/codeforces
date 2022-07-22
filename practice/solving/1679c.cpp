#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

// Segment trees are very cool but painful to implement

const int mxN = 1e5;
ll n, q;
ll segR[2*mxN+1], segC[2*mxN+1];

void Rup(ll index, ll value) {
	index += n;
	segR[index] += value;
	for (index>>=1; index>=1; index>>=1)
		segR[index] = min(segR[index+index], segR[index+index+1]);
}

void Cup(ll index, ll value) {
	index += n;
	segC[index] += value;
	for (index>>=1; index>=1; index>>=1)
		segC[index] = min(segC[index+index], segC[index+index+1]);
}

ll Rmin(ll start, ll end) {
	start += n;
	end += n;
	ll out = 1e16;
	while (start <= end) {
		if (start & 1)
			out = min(out,segR[start++]);
		if (!(end&1))
			out = min(out,segR[end--]);
		start>>=1;
		end>>=1;
	}
	return out;
}

ll Cmin(ll start, ll end) {
	start += n;
	end += n;
	ll out = 1e16;
	while (start <= end) {
		if (start & 1)
			out = min(out,segC[start++]);
		if (!(end&1))
			out = min(out,segC[end--]);
		start>>=1;
		end>>=1;
	}
	return out;
}

void solve() {
	memset(segR, 0, sizeof segR);
	memset(segC, 0, sizeof segC);
	cin >> n >> q;
	
	ll x1,y1,x2,y2;
	for (int i = 0; i < q; i++) {
		int t;
		cin >> t;
		if (t == 1) {
			cin >> x1 >> y1;
			Rup(x1,1);
			Cup(y1,1);
		} else if (t == 2) {
			cin >> x1 >> y1;
			Rup(x1,-1);
			Cup(y1,-1);
		} else {
			cin >> x1 >> y1 >> x2 >> y2;
			cout << (Cmin(y1,y2)||Rmin(x1,x2)?"Yes":"No") << "\n";
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solve();
}

