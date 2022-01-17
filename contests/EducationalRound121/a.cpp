#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    string s;
    cin >> s;
    set<char> chars;
    map<char,int> occurs;
    for (char c : s) {
        occurs[c]++;
        chars.insert(c);
    }
    
    string out = "";
    vector<char> unique(chars.begin(),chars.end());
    for (int i = 0; i < unique.size(); i++) {
        if (occurs[unique[i]] == 2)
            out += unique[i];
        out += unique[i];
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