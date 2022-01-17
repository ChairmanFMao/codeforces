#include <bits/stdc++.h>
using namespace std;
#define ll long long

// First try I get TLE on test 10 as I am using an O(n^3) algorithm that just brute forces it
// I think that for each character I will need to store the number of w after and the number of o after
// Sadly after completely redesigning the algorithm I still get TLE on test 10
// On the third try, with a solution that has linear time it got accepted

void solve() {
    string s;
    cin >> s;

    // The string real is the string but just with the vv properly turned into w characters
    string real = "";
    for (int i = 0; i < s.size(); i++) {
        if (i < s.size()-2) {
            if (s[i] == 'v' && s[i+1] == 'v' && s[i+2] == 'v') {
                real += "w";
                continue;
            }
        } if (i < s.size()-1) {
            if (s[i] == 'v' && s[i+1] == 'v') {
                real += 'w';
                continue;
            }
            if (s[i] == 'v' && s[i+1] == 'o')
                continue;
        } if (s[i] == 'o')
            real += "o";
    }

    ll wBefore[real.size()], wAfter[real.size()];
    int wCount = 0;
    for (int i = 0; i < real.size(); i++) {
        if (real[i] == 'w')
            wCount++;
        wBefore[i] = wCount;
    }
    wCount = 0;
    for (int i = real.size()-1; i >= 0; i--) {
        if (real[i] == 'w')
            wCount++;
        wAfter[i] = wCount;
    }

    ll wows = 0;
    for (int i = 0; i < real.size(); i++)
        if (real[i] == 'o')
            wows += wBefore[i] * wAfter[i];
    
    cout << wows << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}