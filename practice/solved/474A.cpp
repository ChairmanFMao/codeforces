#include <bits/stdc++.h>
using namespace std;

char index(char c, char shift) {
    string keyboard = "qwertyuiopasdfghjkl;zxcvbnm,./";
    for (int i = 0; i < keyboard.length(); i++) {
        if (keyboard[i] == c) {
            return keyboard[i + (shift == 'R' ? -1 : 1)];
        }
    }
    return 0;
}

void solve() {
    char shift;
    string message;
    cin >> shift >> message;
    string out = "";
    for (int i = 0; i < message.length(); i++)
        out += index(message[i], shift);
    cout << out << "\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "\n";
    solve();
}