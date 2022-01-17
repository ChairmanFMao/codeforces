#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    string s, t;
    cin >> s >> t;
    int sa = 0, sb = 0, ta = 0, tb = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'a')
            sa++;
        else
            sb++;
    }
    for (int i = 0; i < t.size(); i++) {
        if (t[i] == 'a')
            ta++;
        else
            tb++;
    }
    if ((double) sa / sb != (double) ta / tb) {
        cout << -1 << "\n";
        return;
    }
    string sout = s, tout = t;
    while (sout != tout) {
        if (sout.size() > tout.size())
            tout += t;
        else
            sout += s;
        // Needed to stop it infinitely going on if it was misjudged
        if (sout.size() > 1000) {
            cout << -1 << "\n";
            return;
        }
    }
    cout << sout << "\n";
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