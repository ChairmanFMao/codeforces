#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(c) (int)c.size()
#define all(c) c.begin(),c.end()

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;

	vector<int> streaks;
	vector<int> s1, s2;
	int streak = 1, parity = 1;
	for (int i = 0; i < sz(s)-1; i++) {
		if (s[i] == s[i+1])
			streak++;
		else {
			if (parity)
				s1.push_back(streak);
			else
				s2.push_back(streak);
			parity ^= 1;
			streaks.push_back(streak);
			streak = 1;
		}
	}
	if (parity)
		s1.push_back(streak);
	else
		s2.push_back(streak);
	streaks.push_back(streak);

	int out = 0;
	for (int i = 0; i < sz(streaks); i++) {
		if (streaks[i] & 1) {
			out++;
			streaks[i+1] ^= 1;
		}
	}

	cout << out << " ";

	if (sz(streaks) == 1) {
		cout << "1\n";
		return;
	}

	// We need to remove the ends
	int first = streaks[0], last = streaks[sz(streaks)-1];
	if (!parity)
		s2.pop_back();
	else
		s1.pop_back();
	s1.erase(s1.begin());

	// We then sort the streaks without the ends
	sort(all(s1));
	sort(all(s2));

	// This finds out how many normal ones can be removed
	bool early = 0, total = first+last;
	int out1 = out, out2 = out;
	int ptr1 = 0, ptr2 = 0;
	while (ptr1 <= sz(s1) && out1 >= 0) {
		if (ptr1 == sz(s1)) {
			ptr1++;
			break;
		}
		if (total < s1[ptr1] && parity) {
			out1 -= total;
			early = 1;
			continue;
		}
		out1 -= s1[ptr1];
		ptr1++;
	}
	while (ptr2 <= sz(s2) && out2 >= 0) {
		if (ptr2 == sz(s2)) {
			ptr2++;
			break;
		}
		out2 -= s2[ptr2];
		ptr2++;
	}

	ptr1--;
	ptr2--;
	// This deals with the ends
	int extra = 0;
	if (parity && !early) {
		int smaller = min(first,last);
		if (out1 >= smaller) {
			out1 -= smaller;
			extra++;
		} if (out1 >= max(first,last)) {
			extra++;
		}
	} else if (!parity && !early) {
		if (out1 >= first)
			extra++;
	}
	
	int extra2 = 0;
	if (!parity) {
		if (out2 >= last)
			extra2++;
	}
	cout << sz(streaks)-max(ptr1+ptr1+extra,ptr2+ptr2+extra2) << "\n";
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

