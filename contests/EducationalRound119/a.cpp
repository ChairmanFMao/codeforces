#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    string s;
    cin >> s;

    int n = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == 'N')
            n++;
    
    string out = n == 1 ? "NO" : "YES";
    cout << out << "\n";
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
