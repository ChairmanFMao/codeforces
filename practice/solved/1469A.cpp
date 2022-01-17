#include <bits/stdc++.h>
using namespace std;
#define ll long long

// First try fail as not vigourous enough testing
// Second try failed due to making a change and not checking
// Third try :)

void solve() {
    string s;
    cin >> s;
    if (s.size() & 1) {
        cout << "NO" << "\n";
        return;
    }
    string strip = "";
    bool removing = 1;
    while (removing) {
        strip = "";
        removing = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i == s.size()-1) {
                strip += s[i];
                break;
            }
            if (s[i] == '(' && s[i+1] == ')') {
                i++;
                removing = 1;
            } else {
                strip += s[i];
            }
        }
        if (strip.size() == 0) {
            cout << "YES" << "\n";
            return;
        }
        s = strip;
    }
    if (strip[0] == ')' || strip[strip.size()-1] == '(') {
        cout << "NO" << "\n";
        return;
    }
    cout << "YES" << "\n";
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