#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n, l;
    cin >> n >> l;

    int out = 0;
    vector<int> words(n);
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }
    
    for (int i = 0; i < 31; i++) {
        int one = 0;
        for (int j = 0; j < n; j++)
            one += 1 << i & words[j] ? 1 : -1;
        if (one > 0) {
            out ^= 1 << i;
        }
    }

    cout << out << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
        solve();
}
