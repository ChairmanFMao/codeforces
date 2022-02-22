
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n;
    string s;
    cin >> n >> s;

    int zero = 0;
    for (char c : s)
        if (c == '0')
            zero++;
    
    vector<int> out;

    for (int i = 0; i < n; i++) {
        if (i < zero && s[i] == '1')
            out.push_back(i+1);
        if (i >= zero && s[i] == '0')
            out.push_back(i+1);
    }
    cout << (out.size() ? "1" : "0") << "\n";
    if (out.size()) {
        cout << out.size() << " ";
        for (int i : out)
            cout << i << " ";
        cout << "\n";
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
