#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Accepted first try!

void solve() {
    int n;
    string s;
    cin >> n >> s;

    // Had to do this to create a new string with the same length as s to replace the letters
    string text = "";
    for (int i = 0; i < s.size(); i++)
        text += ".";
    
    int lptr = 0, rptr = s.size()-1;
    for (int i = 0; i < s.size(); i++) {
        if (i & 1) {
            text[lptr] = s[s.size()-1-i];
            lptr++;
        } else {
            text[rptr] = s[s.size()-1-i];
            rptr--;
        }
    }
    cout << text << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}