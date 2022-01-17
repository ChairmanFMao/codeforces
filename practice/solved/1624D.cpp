#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Did have to look at the tutorial for this one because I was confused by the wording

void solve() {
    int n,k;
    string s;
    vector<int> occurs(26);
    cin >> n >> k >> s;

    for (char c : s)
        occurs[c-97]++;
    
    int pairs = 0, leftOver = 0;
    for (int i = 0; i < 26; i++) {
        pairs += occurs[i]/2;
        leftOver += occurs[i] % 2;
    }

    int out = 2 * (pairs / k);
    leftOver += 2 * (pairs % k);
    if (leftOver >= k)
        out++;
    
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
