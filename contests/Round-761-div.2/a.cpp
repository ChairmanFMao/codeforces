#include <bits/stdc++.h>
using namespace std;
#define ll long long

// WA on pretest 2, I have no idea what I'm doing wrong honestly
// Thought of a counter example, aabbcc with t = "abc"
// Need to move the whole group of c characters infront of the b characters

// Passed all of the pretests!

void solve() {
    string s, t;
    cin >> s >> t;
    sort(s.begin(),s.end());
    if (t == "abc") {
        int bcount = 0, ccount = 0;
        int bloc = 0, cloc = 0;
        bool a = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a')
                a = 1;
            if (s[i] == 'b' && bcount == 0)
                bloc = i;
            if (s[i] == 'b')
                bcount++;
            if (s[i] == 'c' && ccount == 0)
                cloc = i;
            if (s[i] == 'c')
                ccount++;
        }
        if (a && bcount > 0 && ccount > 0) {
            cout << s.substr(0,bloc) + s.substr(cloc,ccount) + s.substr(bloc,bcount) + s.substr(cloc+ccount) << "\n";
            return;
        }
    }
    cout << s << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
        solve();
}