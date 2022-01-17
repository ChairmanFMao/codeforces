#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Failed first try, I edited one of the inputs that was meant to be set
// Accepted second try! I had some function that were a little redundant but it still worked fine.

int questions(string s) {
    int count = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '?')
            count++;
    return count;
}

int shortQuestions(string s) {
    int count = 0;
    for (int i = 1; i < s.size()-1; i++)
        if (s[i] == '?')
            count++;
    return count;
}

void solve() {
    int n;
    string s;
    cin >> n >> s;

    if (questions(s) == s.size()) {
        for (int i = 0; i < s.size(); i++)
            s[i] = i & 1 ? 'R' : 'B';
        cout << s << "\n";
        return;
    }
    while (shortQuestions(s) > 0) {
        for (int i = 1; i < s.size()-1; i++) {
            if (s[i] != '?')
                continue;
            if (s[i-1] == 'B' || s[i+1] == 'B')
                s[i] = 'R';
            if (s[i-1] == 'R' || s[i+1] == 'R')
                s[i] = 'B';
        }
    }
    if (s[0] == '?') {
            if (s[1] == 'B')
                s[0] = 'R';
            else if (s[1] == 'R')
                s[0] = 'B';
    } if (s[s.size()-1] == '?') {
            if (s[s.size()-2] == 'B')
                s[s.size()-1] = 'R';
            else if (s[s.size()-2] == 'R')
                s[s.size()-1] = 'B';
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