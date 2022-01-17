#include <bits/stdc++.h>
using namespace std;
#define ll long long

// WA on pretest 2, unsure why
// Still WA on pretest 2 when I made the algorithm better, unsure why this is the case
// Brute force, slow one times out on test 4
// There was just a minor edge case

void solve() {
    int n;
    string s;
    cin >> n >> s;

    // string out = "";
    // for (int i = 1; i <= n; i++) {
    //     string current = s.substr(0,i);
    //     reverse(current.begin(), current.end());
    //     current = s.substr(0,i) + current;
    //     if (current < out || out == "")
    //         out = current;
    // }
    // string first = out;
    // cout << out << "\n";

    char current = s[0];
    string out = "";
    for (int i = 0; i < n && s[i] <= current; ++i) {
        out += s[i];
        current = s[i];
    }
    if (n >= 2) {
        if (s[0] == s[1])
            out = s.substr(0,1);
    }
    string second = out;
    reverse(out.begin(),out.end());
    second += out;
    cout << second << "\n";

    // if (first != second) {
    //     cout << s << " " << first << " " << second << "\n";
    // }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
        solve();
}