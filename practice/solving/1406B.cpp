#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n;
    cin >> n;
    vector<int> neg, pos;
    for (int i = 0,a; i < n; i++) {
        cin >> a;
        if (a < 0)
            neg.push_back(a);
        else
            pos.push_back(a);
    }
    ll best = 1, nptr = 0, pptr = 0, current, sign;
    sort(neg.begin(),neg.end());
    sort(pos.begin(),pos.end());
    reverse(pos.begin(),pos.end());
    for (int i = 0; i < 2; i++) {
        sign = 0;
        current = 0;
        if (nptr < (int)neg.size()-2) {
            if (current < neg[nptr]*neg[nptr+1]) {
                sign = 0;
                current = neg[nptr]*neg[nptr+1];
            }
        }
        if (pptr < (int)pos.size()-2) {
            if (current < pos[pptr]*pos[pptr+1]) {
                sign = 1;
                current = pos[pptr]*pos[pptr+1];
            }
        }
        best *= current;
        if (current)
            nptr += 2;
        else
            pptr += 2;
    }

    if (pptr < (int)pos.size()-1)
        best *= pos[pptr];
    else
        best *= neg[neg.size()-1];

    cout << best << "\n";
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
