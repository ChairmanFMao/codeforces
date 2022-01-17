#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Accepted first try :)

int many(string s, string sub) {
    int count = 0;
    for (int i = 0; i < s.length()-1; i++) {
        if (s[i] == sub[0] && s[i+1] == sub[1]) {
            count++;
            i++;
        }
    }
    return count;
}

void solve() {
    string s;
    cin >> s;
    string ab = "ab", ba = "ba";
    if (many(s,ab) != many(s,ba)) {
        s[0] = 'a';
        s[s.length()-1] = 'a';
    }
    cout << s << "\n";
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