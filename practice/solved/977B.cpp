#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string twogram = "";
    int count = 0;
    for (int i = 0; i < n - 1; i++) {
        string current = s.substr(i,2);
        int number = 0;
        for (int j = 0; j < n - 1; j++) {
            if (current == s.substr(j,2))
                number++;
        }
        if (number > count) {
            count = number;
            twogram = current;
        }
    }
    cout << twogram << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "\n";
    solve();
}