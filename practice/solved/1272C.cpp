#include <bits/stdc++.h>
using namespace std;
#define ll long long

// For each contiguous substring of characters on the keyboard, you add the triangle number of the length of it to the possible combos you can make.
// Failed first time, WA test 12, due to integer overflow
// Accepted second try! I simply converted out and streak to be ll

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    set<char> keyboard;
    for (int i = 0; i < k; i++) {
        char a;
        cin >> a;
        keyboard.insert(a);
    }
    
    ll out = 0;
    ll streak = 0;
    for (int i = 0; i < s.size(); i++) {
        if (keyboard.count(s[i])) {
            streak++;
        } else {
            out += (streak*streak + streak)/2;
            streak = 0;
        }
    }
    out += (streak*streak + streak)/2;
    cout << out << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}