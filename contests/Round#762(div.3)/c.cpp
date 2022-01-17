#include <bits/stdc++.h>
using namespace std;
#define ll long long

// WA on test 2 first try, not sure where the error is
// After a little debugging, got WA on test 2 again
// Found the error and it was accepted

bool validate(string goal, string f, string s) {
    string out = "";
    int biggest = max(f.size(), s.size());
    while (f.size() != biggest)
        f = "0" + f;
    while (s.size() != biggest)
        s = "0" + s;
    
    for (int i = 0; i < s.size(); i++)
        out += to_string(f[i] - 48 + s[i] - 48);
    
    return out == goal;
}

void solve() {
    ll a, s;
    cin >> a >> s;

    string sString = to_string(s), aString = to_string(a);
    ll out = 0;
    int sptr = sString.size()-1, aptr = aString.size()-1;
    ll magnitude = 1;
    while (sptr >= 0 && aptr >= 0) {
        if (sString[sptr] < aString[aptr]) {
            if (sString[sptr-1] != '1') {
                cout << -1 << "\n";
                return;
            }
            out += (10 + sString[sptr] - aString[aptr]) * magnitude;
            sptr -= 2;
            aptr--;
        } else {
            out += (sString[sptr] - aString[aptr]) * magnitude;
            sptr--;
            aptr--;
        }
        magnitude *= 10;
    }
    // Needed to turn this into a while from an if
    while (sptr >= 0) {
        out += magnitude * (sString[sptr] - 48);
        sptr--;
        magnitude *= 10;
    }
    // Currently having a problem checking if the output is valid
    if (validate(sString,aString,to_string(out)))
        cout << out << "\n";
    else
        cout << -1 << "\n";
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