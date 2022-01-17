#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Failed first time, WA test 1
// Looked at solution because spent most of a day thinking about it and couldn't figure it out
// Failed second time, WA test 1, just sloppy and not checking properly that code worked
// Failed third time, WA test 2
// Accepted fourth try!
// Overall kinda poor performance, need to test code throughly before submitting

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    bool asc = 1;
    for (int i = 0; i < n-1; i++) {
        if (s[i] > s[i+1])
            asc = 0;
    }
    if (asc) {
        cout << s << "\n";
        return;
    }
    string out = "0";
    int front = 0, back = n-1;
    while (s[front] == '0') {
        out += '0';
        front++;
    }
    while (s[back] == '1') {
        out += '1';
        back--;
    }
    cout << out << "\n";
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