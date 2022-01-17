#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Failed on first try, RE on test 2, I had an error with infinite looping I think
// Accepted second try!

void solve() {
    int n;
    cin >> n;
    vector<int> odd, even;
    for (int i = 0; i < 2*n; i++) {
        int a;
        cin >> a;
        if (a & 1)
            odd.push_back(i+1);
        else
            even.push_back(i+1);
    }

    int out = 0, ptr = 0, optr = 0, es = even.size()-1, os = odd.size()-1;
    while (out < n-1) {
        if (ptr < es) {
            cout << even[ptr] << " " << even[ptr+1] << "\n";
            out++;
            ptr+=2;
        } else if (optr < os) {
            cout << odd[optr] << " " << odd[optr+1] << "\n";
            out++;
            optr+=2;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "\n";
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve();
}